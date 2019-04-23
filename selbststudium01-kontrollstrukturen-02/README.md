# Zählen von Zeichen und Wörtern
## Aufgabe
Schreiben Sie ein Programm in C, welches die Zeichen und Wörter einer mit der Tastatur eingegebenen Zeile zählt. Wortzwischenräume sind entweder Leerzeichen (' ') oder Tabulator-zeichen ('\t'). Eine Zeile wird bei der Eingabe mit einem Newline-Character ('\n') abgeschlossen, worauf das Programm die Anzahl Zeichen (ohne dem abschliessenden NewlineCharacter) und Wörter ausgeben und terminieren soll.

## Hinweise
Lesen Sie die einzelnen Zeichen mit der Funktion `int getchar(void)` aus der `stdio.h` Library ein. Die Funktion `getchar` kehrt nicht gleich bei Eingabe des ersten Zeichens zurück, sondern puffert die Daten, bis die Eingabe einer kompletten Zeile mit Return abgeschlossen wird. Dann wird das erste Zeichen aus dem Puffer zurückgegeben und mit weiteren Aufrufen von `getchar` können die nachfolgenden Zeichen aus dem Puffer gelesen werden. Gibt getchar `'\n'` zurück, ist die Zeile komplett zurückgegeben und der Puffer ist wieder leer.