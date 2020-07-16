Huffman-Kodierung 
Alexey Prays 
Hochschule Emden/Leer
2 Semester Informatik

Ordnerstruktur:

Cress
   |
   ├── bin                       // Dieses Ordner enthält die cress und cress_test binaries.
   ├── data                      // Dieses Ordner enthält die Test-Dateien.
   ├── include                   // Dieses Ordner enthält die Header-Dateien.
   │   ├── Application           
   │   ├── Compression
   │   ├── DataStructure
   │   ├── Entropy
   │   └── FileHandling
   ├── libs                      // Dieses Ordner enthält die Cache2 Header-Datei.
   ├── scripts                   // Dieses Ordner enthält die Skripts.
   ├── src                       // Dieses Ordner enthält die Quelldateien
   │   ├── Application
   │   ├── Compression
   │   ├── DataStructure
   │   ├── Entropy
   │   └── FileHandling
   └── tests                     // Dieses Ordner enthält Test-Quelldateie.


Externe Abhängigkeiten:
   Make
      Eine Alternative zum make sind die Build-Skripts.
   Catch2
      Wird mitgeliefert.


Beschreibung:
   Bei diesem Projekt handelt es sich um meine Implementierung des Huffman Compressions-Algorithmus.
   Es sollte dabei keine voll-funktionsfähige Anwendung erstellt werden, sondern lediglich nur die Grund Funktionalität wie in der
   ersten Quelle beschrieben implementiert werden(eine Art POC). Bei vorliegender Interesse würde ich das Testen auf kleinere Text-Dateien begrenzen(kleiner als 15 MB).
   Ich habe diese Anwendung mit Quelltext-Dateien und Kompilierten C++ Anwendungen getestet. Dabei erhielt ich eine Größenreduktion
   im Bereich von ca. 40-70%. Dieser Algorithmus funktioniert nur bei Dateien mit niedriger Informations-Entropie, falls man versucht Bilder zu Kompressieren
   kommt es meistens zum Größenzuwachs, das hat wahrscheinlich damit zu tun, dass Bild-Formate wie .png und .jpg selber kompressionen vornehmen
   und eine hohe Entropie besitzen, einen Größenzuwachs nach der Kompression stellte ich auch bei Dateiformaten wie .pdf fest.


Topics:
   Die implementiereten Topics wurden im Quellcode Kommentiert. Für das einfachere suchen der Topics wurden alle
   kommentare mit dem schlüsselwort [TOPIC] versehen.

   Überblick:
      <grep -rnw -e "TOPIC"> Im Quellverzeichniss ausführen.


Kompilation:
   Folgende Build Skripte können verwendet werden:

      benchmark.sh 
         Alle Daten in dem /cress/data Verzeichniss werden kompressiert und dekompressiert, 
         dabei wird die dauer beider Operationen gemessen, außerdem wird dabei sichergestellt,
         dass alle Dateien richtig entpackt wurden, die größenreduktion und die Informations-Entropie ist auch zu sehen.

      run_tests.sh
         Die Tests.cpp Datei wird kompiliert, diese Datei benutzt das Catch2 Framework um mehrere Tests zu durchzuführen.
         Es werden die Bit Datenstrukturen und Operationen getestet und das Kompressieren und Dekompressieren.

      build_tests.sh | Make alternative <make tests>
         Es wird nur die tests binary kompliliert und nicht automatisch ausgeführt.

      build.sh | Make alternative <make>
         Die default Cress Binary wird erstellt.


Bedienung:
   ./cress -c <Filename> : Compress
   ./cress -d <Filename> : Decompress
   ./cress -e <Filename> : Shannon Entropy 
   ./cress -h            : Banner und Info


Quellen:

   Huffman
   http://web.stanford.edu/class/archive/cs/cs106x/cs106x.1192/resources/minibrowser2/huffman-encoding-supplement.pdf
   https://riptutorial.com/algorithm/example/23995/huffman-coding

   Shannon Entropy
   http://bearcave.com/misl/misl_tech/wavelets/compression/shannon.html

   C++
   https://en.cppreference.com/w/cpp/language/operators
   https://stackoverflow.com/questions/18816126/c-read-the-whole-file-in-buffer
   http://peterforgacs.github.io/2017/06/25/Custom-C-Exceptions-For-Beginners/

   Mmap
   https://man7.org/linux/man-pages/man2/mmap.2.html

   Misc
   https://stackoverflow.com/questions/51469927/huffman-compression-images
   https://stackoverflow.com/questions/45354875/using-huffman-coding-to-compress-images-taken-by-the-iphone-camera
