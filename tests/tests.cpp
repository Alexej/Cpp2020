#define CATCH_CONFIG_MAIN 
#include "../include/Compression/HuffmanCompression.hpp"
#include "../include/DataStructure/BitVector.hpp"
#include "../include/DataStructure/BitField.hpp"
#include "../libs/catch.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>


std::string data = R"(Consulted he eagerness unfeeling deficient existence of. Calling nothing end fertile for venture way boy. Esteem spirit temper too say adieus who direct esteem. It esteems luckily mr or picture placing drawing no. Apartments frequently or motionless on reasonable projecting expression. Way mrs end gave tall walk fact bed. 
Detract yet delight written farther his general. If in so bred at dare rose lose good. Feel and make two real miss use easy. Celebrated delightful an especially increasing instrument am. Indulgence contrasted sufficient to unpleasant in in insensible favourable. Latter remark hunted enough vulgar say man. Sitting hearted on it without me. 
Blind would equal while oh mr do style. Lain led and fact none. One preferred sportsmen resolving the happiness continued. High at of in loud rich true. Oh conveying do immediate acuteness in he. Equally welcome her set nothing has gravity whether parties. Fertile suppose shyness mr up pointed in staying on respect. 
Difficulty on insensible reasonable in. From as went he they. Preference themselves me as thoroughly partiality considered on in estimating. Middletons acceptance discovered projecting so is so or. In or attachment inquietude remarkably comparison at an. Is surrounded prosperous stimulated am me discretion expression. But truth being state can she china widow. Occasional preference fat remarkably now projecting uncommonly dissimilar. Sentiments projection particular companions interested do at my delightful. Listening newspaper in advantage frankness to concluded unwilling. 
Up maids me an ample stood given. Certainty say suffering his him collected intention promotion. Hill sold ham men made lose case. Views abode law heard jokes too. Was are delightful solicitude discovered collecting man day. Resolving neglected sir tolerably but existence conveying for. Day his put off unaffected literature partiality inhabiting. 
Boisterous he on understood attachment as entreaties ye devonshire. In mile an form snug were been sell. Hastened admitted joy nor absolute gay its. Extremely ham any his departure for contained curiosity defective. Way now instrument had eat diminution melancholy expression sentiments stimulated. One built fat you out manor books. Mrs interested now his affronting inquietude contrasted cultivated. Lasting showing expense greater on colonel no. 
Yet remarkably appearance get him his projection. Diverted endeavor bed peculiar men the not desirous. Acuteness abilities ask can offending furnished fulfilled sex. Warrant fifteen exposed ye at mistake. Blush since so in noisy still built up an again. As young ye hopes no he place means. Partiality diminution gay yet entreaties admiration. In mr it he mention perhaps attempt pointed suppose. Unknown ye chamber of warrant of norland arrived. 
Placing assured be if removed it besides on. Far shed each high read are men over day. Afraid we praise lively he suffer family estate is. Ample order up in of in ready. Timed blind had now those ought set often which. Or snug dull he show more true wish. No at many deny away miss evil. On in so indeed spirit an mother. Amounted old strictly but marianne admitted. People former is remove remain as. 
She who arrival end how fertile enabled. Brother she add yet see minuter natural smiling article painted. Themselves at dispatched interested insensible am be prosperous reasonably it. In either so spring wished. Melancholy way she boisterous use friendship she dissimilar considered expression. Sex quick arose mrs lived. Mr things do plenty others an vanity myself waited to. Always parish tastes at as mr father dining at. 
In on announcing if of comparison pianoforte projection. Maids hoped gay yet bed asked blind dried point. On abroad danger likely regret twenty edward do. Too horrible consider followed may differed age. An rest if more five mr of. Age just her rank met down way. Attended required so in cheerful an. Domestic replying she resolved him for did. Rather in lasted no within no. 
)";

void 
writeDataToFile(std::string filename)
{
    std::ofstream file(filename, std::ios::out | std::ios::binary);
    file << data;
    file.close();
}

void 
readDataFromFile(std::string filename, std::vector<char> & vec)
{
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    file.seekg(0, std::ios_base::end);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);
    vec.resize(size);
    file.read(vec.data(), size);
    file.close();
}


TEST_CASE( "Testing Compression and Decompression", "[cress]" ) 
{
    const std::string filename = "test.txt";
    writeDataToFile(filename);
    Cress::Compression::HuffmanCompression(filename, Cress::Compression::Mode::COMPRESSION);
    Cress::Compression::HuffmanCompression(filename + ".c", Cress::Compression::Mode::DECOMRESSION);

    std::vector<char> inVec;
    readDataFromFile(filename+ ".d", inVec);

    std::string dataFromFile;
    for(auto ch : inVec)
        dataFromFile += ch;

    REQUIRE( data == dataFromFile );
}

TEST_CASE("Testing BitFields and BitVectors", "[bit manipulation]")
{
    std::vector<std::string> letters;
    std::vector<int8_t> test;

    letters.push_back("1100000001"); // C
    letters.push_back("0011");       // o
    letters.push_back("1010");       // n
    letters.push_back("0110");       // s
    letters.push_back("00000");      // u
    letters.push_back("10111");      // l
    letters.push_back("1000");       // t
    letters.push_back("010");        // e
    letters.push_back("11001");      // d


/*
   [TOPIC](6) Daten: Umwandlung
*/
    test.push_back((int8_t)192);
    test.push_back((int8_t)78);
    test.push_back((int8_t)152);
    test.push_back((int8_t)23);
    test.push_back((int8_t)133);
    test.push_back((int8_t)144);

    using namespace Cress::DataStructure;
    BitField bitFieldArr[9];
    BitVector bv;

    for(std::size_t i = 0; i < letters.size(); ++i)
    {
        for(std::size_t j = 0; j < letters[i].size(); ++j)
            letters[i][j] == '1' ? bitFieldArr[i].append(1) : bitFieldArr[i].append(0);
        bv.addBits(bitFieldArr[i]);
    }
/*
    printf("%i == %i\n", test[0], bv.vector()[0]);
    printf("%i == %i\n", test[1], bv.vector()[1]);
    printf("%i == %i\n", test[2], bv.vector()[2]);
    printf("%i == %i\n", test[3], bv.vector()[3]);
    printf("%i == %i\n", test[4], bv.vector()[4]);
    printf("%i == %i\n", test[5], bv.vector()[5]);
*/
    REQUIRE(test[0] == bv.vector()[0]);
    REQUIRE(test[1] == bv.vector()[1]);
    REQUIRE(test[2] == bv.vector()[2]);
    REQUIRE(test[3] == bv.vector()[3]);
    REQUIRE(test[4] == bv.vector()[4]);
    REQUIRE(test[5] == bv.vector()[5]);
}

TEST_CASE("Testing BitVector edge case", "[3 bytes]")
{
    using namespace Cress::DataStructure;
    BitField bf1, bf2;
    BitVector bv;
    std::vector<int8_t> test;

    test.push_back((int8_t)171);
    test.push_back((int8_t)255);
    test.push_back((int8_t)224);

    bf1.append(1);
    bf1.append(0);
    bf1.append(1);
    bf1.append(0);
    bf1.append(1);
    bf1.append(0);
    bf1.append(1);

    bf2.append(1);
    bf2.append(1);
    bf2.append(1);
    bf2.append(1);
    bf2.append(1);
    bf2.append(1);
    bf2.append(1);
    bf2.append(1);
    bf2.append(1);
    bf2.append(1);
    bf2.append(1);
    bf2.append(1);

    bv.addBits(bf1);
    bv.addBits(bf2);
/*
    printf("%i == %i\n", test[0], bv.vector()[0]);
    printf("%i == %i\n", test[1], bv.vector()[1]);
    printf("%i == %i\n", test[2], bv.vector()[2]);
*/
    REQUIRE(test[0] == bv.vector()[0]);
    REQUIRE(test[1] == bv.vector()[1]);
    REQUIRE(test[2] == bv.vector()[2]);
}