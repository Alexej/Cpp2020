#define CATCH_CONFIG_MAIN 
#include "../include/Compression/Huffman.hpp"
#include "../include/DataStructure/BitVector.hpp"
#include "../include/DataStructure/BitField.hpp"
#include "../libs/catch.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>


std::string data = R"(One morning, when Gregor Samsa woke from troubled dreams, he found himself transformed in his bed into a horrible vermin. He lay on his armour-like back,
and if he lifted his head a little he could see his brown belly, slightly domed and divided by arches into stiff sections. The bedding was hardly able to
cover it and seemed ready to slide off any moment. His many legs, pitifully thin compared with the size of the rest of him, waved about helplessly as he looked.
"What's happened to me?" he thought. It wasn't a dream. His room, a proper human room although a little too small, lay peacefully between its four familiar walls.
A collection of textile samples lay spread out on the table - Samsa was a travelling salesman - and above it there hung a picture that he had recently cut out
of an illustrated magazine and housed in a nice, gilded frame. It showed a lady fitted out with a fur hat and fur boa who sat upright, raising a heavy fur muff
that covered the whole of her lower arm towards the viewer. Gregor then turned to look out the window at the dull weather. Drops of rain could be heard hitting
the pane, which made him feel quite sad. "How about if I sleep a little bit longer and forget all this nonsense", he thought, but that was something he was 
unable to do because he was used to sleeping on his right, and in his present state couldn't get into that position. However hard he threw himself onto his 
right, he always rolled back to where he was. He must have tried it a hundred times, shut his eyes so that he wouldn't have to look at the floundering legs, 
and only stopped when he began to feel a mild, dull pain there that he had never felt before. "Oh, God", he thought, "what a strenuous career it is that I've 
chosen! Travelling day in and day out. Doing business like this takes much more effort than doing your own business at home, and on top of that there's the 
curse of travelling, worries about making train connections, bad and irregular food, contact with different people all the time so that you can never get to 
know anyone or become friendly with them. It can all go to Hell!" He felt a slight itch up on his belly; pushed himself slowly up on his back towards the 
headboard so that he could lift his head better; found where the itch was, and saw that it was covered with lots of little white spots which he didn't know 
what to make of; and when he tried to feel the place with one of his legs he drew it quickly back because as soon as he touched it he was overcome by a cold shudder.
He slid back into his former position. "Getting up early all the time", he thought, "it makes you stupid. You've got to get enough sleep. Other travelling salesmen 
live a life of luxury. For instance, whenever I go back to the guest house during the morning to copy out the contract, these gentlemen are always still sitting 
there eating their breakfasts. I ought to just try that with my boss; I'd get kicked out on the spot. But who knows, maybe that would be the best thing for me. 
If I didn't have my parents to think about I'd have given in my notice a long time ago, I'd have gone up to the boss and told him just what I think, tell him 
everything I would, let him know just what I feel. He'd fall right off his desk! And it's a funny sort of business to be sitting up there at your desk, talking 
down at your subordinates from up there, especially when you have to go right up close because the boss is hard of hearing. Well, there's still some hope; once I've
got the money together to pay off my parents' debt to him - another five or six years I suppose - that's definitely what I'll do. That's when I'll make the big 
change. First of all though, I've got to get up, my train leaves at five." And he looked over at the alarm clock, ticking on the chest of drawers. "God in Heaven!"
he thought. It was half past six and the hands were quietly moving forwards, it was even later than half past, more like quarter to seven. Had the alarm clock not
rung? He could see from the bed that it had been set for four o'clock as it should have been; it certainly must have rung. Yes, but was it possible to quietly 
sleep through that furniture-rattling noise? True, he had not slept peacefully, but probably all the more deeply because of that. What should he do now? 
The next train went at seven; if he were to catch that he would have to rush like mad and the collection of samples was still not packed, and he did not 
at all feel particularly fresh and lively. And even if he did catch the train he would not avoid his boss's anger as the office assistant would have been
there to see the five o'clock train go, he would have put in his report about Gregor's not being there a long time ago. The office assistant was the boss's man,
spineless, and with no understanding. What about if he reported sick? But that would be extremely strained and suspicious as in fifteen years of service 
Gregor had never once yet been ill. His boss would certainly come round with the doctor from the medical insurance company, accuse his parents of having 
a lazy son, and accept the doctor's recommendation not to make any claim as the doctor believed that no-one was ever ill but that many were workshy. 
And what's more, would he have been entirely wrong in this case? Gregor
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


TEST_CASE( "Testing Compression and Decompression", "[Cpp2020]" ) 
{
    const std::string filename = "test.txt";
    writeDataToFile(filename);
    Cpp2020::Compression::Huffman(filename, Cpp2020::Compression::Mode::COMPRESSION);
    Cpp2020::Compression::Huffman(filename + ".c", Cpp2020::Compression::Mode::DECOMRESSION);

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


    test.push_back((int8_t)192);
    test.push_back((int8_t)78);
    test.push_back((int8_t)152);
    test.push_back((int8_t)23);
    test.push_back((int8_t)133);
    test.push_back((int8_t)144);

    Cpp2020::DataStructure::BitField bitFieldArr[9];
    Cpp2020::DataStructure::BitVector bv;

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
    Cpp2020::DataStructure::BitField bf1, bf2;
    Cpp2020::DataStructure::BitVector bv;
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