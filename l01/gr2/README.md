# Laborator 1 Grupa 2 - POO

Directorul conține programe exemplu pentru gestionarea listelor în C++, cu implementare minimală (funcții de alocare, append, print, delete). Fiecare fișier demonstrează o abordare diferită a scrierii listelor, în stiluri diferite de programare (programare procedurală stil C cu funcții globale, programare procedurală stil C cu pointeri la funcții, programare orientată pe obiecte stil C++).

## Fișiere

### ex1_liste_cu_functii_globale.cpp

Acest program demonstrează crearea, afișarea și ștergerea unei liste simplu înlănțuite folosind funcții globale. Structura `Node` este utilizată pentru a stoca informații și un pointer către următorul nod, iar structura `List` gestionează nodurile listei. Operațiile de bază incluse sunt adăugarea unui nod, afișarea listei și eliberarea memoriei alocate.

### ex2_liste_cu_pointeri_la_functii_in_structuri.cpp

Similar cu primul exemplu, acest program ilustrează gestionarea listelor simplu înlănțuite, dar introduce conceptul de pointeri la funcții în structuri. Acest lucru permite ca operațiile de adăugare, afișare și ștergere să fie asociate direct cu structura listei, îmbunătățind modularitatea codului. Acest cod, deși arată mai complicat, seamană mai mult cu ce se intamplă cu adevarat în C++, și dacă întelegeți ideea de pointeri la funcții o să vă fie mai ușor pe viitor la funcții virtuale, și de asemena este un exemplu bun care ilustrează faptul că tot trimitem ca prim parametru adresa variabilei, ceea ce introduce conceptul de necesitate a pointerului implicit `this`, pentru a simplifica lucrurile.

### ex3_liste_cu_clase.cpp

Ultimul exemplu avansează abordarea prin utilizarea claselor pentru gestionarea listelor. Programul definește o clasă `List` care încapsulează funcționalitățile de bază: adăugarea unui nod, afișarea conținutului și distrugerea listei. Aceasta demonstrează principiile de bază ale programării orientate pe obiect, cum ar fi încapsularea și utilizarea constructorilor și destructorilor pentru gestionarea resurselor. Nu am mai fost nevoiți să apelăm funcția de eliberare a listei manual, deoarece destructorul s-a apelat automat imediat când a ieșit variabila locală din scop, în cazul actual la finalul funcției main().

## Utilizare

Pentru a compila oricare dintre programe, folosiți un compilator C++ compatibil, în cazul nostru, am folsit g++ la laborator, însă evident că nu este singurul. Observație: numele executabilului, specificat după flag-ul -o (output) poate să fie orice doriți voi, însă, dacă ați schimbat numele executabilului, trebuie sa schimbați numele acestuia și la rulare.

Exemplu de comandă de compilare pentru al treilea program:
```
g++ -o ex3_liste_cu_clase ex3_liste_cu_clase.cpp
```

Pentru a rula oricare dintre programe, folosiți un terminal sau direct din editorul de cod (IDE). Exemplu de comandă de rulare pentru programul `ex3_liste_cu_clase.cpp` din terminal:

Pentru bash (Linux/Mac/WSL):
```
./ex3_liste_cu_clase
```
Pentru Command Prompt (Windows)
```
ex3_liste_cu_clase.exe
```

În ambele instanțe, output-ul din consolă ar trebui să arate în felul următor pentru `ex3_liste_cu_clase.cpp`:
```
Constructor apelat
Append apelat
Append apelat
Print apelat
10
20
Destructor apelat
```

**IMPORTANT PENTRU VIITOR** - Concepte de Sisteme de Operare și script-uri batch (Ulterior vom face exemple de Makefile pentru Linux/MacOS).
în folder-ul actual, am inclus de asemenea 3 script-uri batch (.bat), care practic sunt mai multe comenzi rulate consecutiv în Command Prompt. Puteți deschide fișierele pentru a le vedea conținutul. Pentru programul `ex3_build_and_run.bat`, conținutul fișierului este următorul:
```
g++ -o ex3_liste_cu_clase ex3_liste_cu_clase.cpp
ex3_liste_cu_clase.exe
rem Comanda "@echo off" face ca de acum incolo sa nu se afiseze in terminal comenzile urmatoare executate
@echo off
rem Terminalul s-ar inchide in momentul in care se afiseaza rezultatul programului, deci il tinem deschis pana utilizatorul apasa o tasta sau il inchide explicit
pause >nul
```

Aceste fișiere .bat puteți să le rulați cu dublu-click și vor executa programul direct.