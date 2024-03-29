Huffman-Kodierung 
Alexey Prays 
Hochschule Emden/Leer
2 Semester Informatik
Prof: C. Link


Externe Abhängigkeiten:
   Make
      Eine Alternative zum make sind die Build-Skripts.
   Catch2
      Wird mitgeliefert.


Beschreibung:
   Bei diesem Projekt handelt es sich um meine Implementierung des Huffman Kompressionsalgorithmus.
   Es sollte dabei keine voll-funktionsfähige Anwendung erstellt werden, sondern lediglich nur die Grundfunktionalität wie in der
   ersten Quelle beschrieben implementiert werden(eine Art POC). Bei vorliegender Interesse würde ich das Testen auf kleinere Text-Dateien begrenzen(kleiner als 15 MB).
   Ich habe diese Anwendung mit Quelltext-Dateien und Kompilierten C++ Anwendungen getestet. Dabei erhielt ich eine Größenreduktion
   im Bereich von ca. 40-70%. Dieser Algorithmus funktioniert nur bei Dateien mit niedriger Informations-Entropie, falls man versucht Bilder zu Kompressieren
   kommt es meistens zum Größenzuwachs, das hat wahrscheinlich damit zu tun, dass Bild-Formate wie .png und .jpg selber kompressionen vornehmen
   und eine hohe Entropie besitzen, einen Größenzuwachs nach der Kompression stellte ich auch bei Dateiformaten wie .pdf fest. 
   
   Da ich so ein Projekt zum ersten Mal
   mache und davor keine Ahnung von Kompressionsalgorithmen oder Koplexen Datenstrukturen hatte, konnte ich nicht die Effizienz erreichen, die man von so einem Programm
   erwarten würde.


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
   ./cress -h            : Banner and Info


Quellen:
   Huffman
   http://web.stanford.edu/class/archive/cs/cs106x/cs106x.1192/resources/minibrowser2/huffman-encoding-supplement.pdf
   https://riptutorial.com/algorithm/example/23995/huffman-coding

   Shannon Entropy
   http://bearcave.com/misl/misl_tech/wavelets/compression/shannon.html

   C++
   http://peterforgacs.github.io/2017/06/25/Custom-C-Exceptions-For-Beginners/
   https://en.wikibooks.org/wiki/More_C++_Idioms/Erase-Remove

   Mmap
   https://man7.org/linux/man-pages/man2/mmap.2.html

   Misc
   https://stackoverflow.com/questions/51469927/huffman-compression-images
   https://stackoverflow.com/questions/45354875/using-huffman-coding-to-compress-images-taken-by-the-iphone-camera
