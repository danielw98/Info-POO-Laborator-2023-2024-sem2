# Programare Orientată pe Obiecte (POO) - Laborator 2023-2024

Repository-ul conține materialele necesare laboratorului de Programare Orientată pe Obiecte pentru grupa 133 profilul informatică, semestrul II, anul universitar 2023-2024, Facultatea de Matematica și Informatică din Universitatea București.

Laborant și autor materiale: Daniel Wagner


## Despre Laborator

Laboratorul de POO are ca scop introducerea și aprofundarea conceptelor fundamentale ale programării orientate pe obiect în limbajul C++. Studenții vor învăța să modeleze și să implementeze soluții software folosind clase, obiecte, moștenire, polimorfism și alte caracteristici ale limbajului C++.


## Notare

Nota finală la materia Programare Orientată pe Obiecte este obținută astfel:
- **1)**: 25% proiecte laborator
- **2)**: 25% colocviu laborator
- **3)**: 50% examen curs

Unde fiecare dintre note trebuie să fie minim 5 (nu rotunjit în sus) pentru a putea promova la următoarea etapă a evaluării.


## Bonusuri

Studenții pot obține în cadrul orelor de laborator și punctaje bonus pentru participarea activă sau diverse activități care asistă învățarea, în valoare maximă de 1p, unde doamna profesoara va decide ce înseamnă acel 1p la examen (presupun că 5% din cei 50% acordați examenului, vom afla la finalul semestrului).


## Structura Repo-ului

- **l01**: Introducere în limbajul C++ și conceptele de bază ale POO - trecerea de la structuri cu funcții globale cu prim parametru pointer către structură, la structuri cu pointeri la funcții cu prim parametru pointer către structură, la clase, ilustrând progresiv pe un exemplu cu Liste simplu înlănțuite trecerea de la structuri la clase și cum apare natural pointer-ul `this`.

- **l02**: Introducere în POO în C++ și Pointeri”, abordând utilizarea pointerilor și a referințelor în C++, cu accent pe pointerii către membrii claselor și funcții. Laboratorul 2 introduce noțiunile de constuctor, getters & setters, constructor de copiere, operator=, destructor, și ilustrează conceptul de deep-copy asupra unui array char*, precum și operatorii `new` și `delete`.

- **l03**: "Supraîncărcarea Operatorilor", explorând conceptul de supraîncărcare în C++, inclusiv supraîncărcarea operatorilor de citire și scriere (operator<< și operator>>), și operații matematice, folosind drept exemplu clasa `Vector2D`. Laboratorul 3 introduce și conceptul de liste de inițializare și funcții prietene (friend), dar și utilizarea parametrilor impliciți la funcții.

- **l04**: Se concentrează pe utilizarea STL (Standard Template Library), evidențiind importanța containerelor, iteratoarelor și algoritmilor din librăria standard pentru dezvoltarea eficientă în C++. Laboratorul 4 de asemenea conține alte informații utile, precum redirecționarea input-ului din fișiere, sugestia de a folosi private/protected pentru metode care nu sunt apelate din afara clasei, și sintaxa nouă pentru liste de inițializare introdusă în C++11.

- **l05**: Introducere în moștenire (inheritance) în C++, detaliind implementarea ierarhiilor de clase, conceptul de clasă de bază și clasă derivată, modificatorii de acces la moștenire, ordinea apelării constructorilor și ordinea apelării destructorilor în ierarhia de clase, precum și exemple practice de upcasting și downcasting pe obiecte derivate din `Persoana`: `Student`, `Parinte`, `Angajat`. În cadrul Laboratului 5, am introdus și `static_cast<T>(obj)` și `dynamic_cast<T>(obj)`, despre care vom vedea mai multe detalii în Laboratorul 7. 


## Proiecte Semestriale

Pe parcursul semestrului, veți avea 3 proiecte, și la fiecare dintre proiecte puteți obține nota maximă 12.

Media finală va fi media notelor obținute în proiecte:
- (Proiect_1 + Proiect_2 + Proiect_3) / 3 
sau 
- 0.33 * Proiect_1 + 0.67 * Proiect_2_plus_3

Unde nota finală este rotunjită în sus după pragul de 0.3 (spre exemplu, 8.3 va fi considerat 9), însă mediile peste 10 vor fi trunchiate și veți obtine cei 25% din proiecte. Rotunjirea notei va fi făcută la final, nu la fiecare proiect în parte.

Cerințele pentru proiecte au fost preluate și adaptate de pe GitHub-ul lui Marius, pe care îl găsiți [aici](https://github.com/mcmarius/poo/).

### Proiectul 1

Cerințele specifice proiectului se află în fișierul `Proiect1_POO_Grupa133.pdf`.

**Termen Limită Predare:** Laborator proiect săptămâna a 6-a (3 Aprilie 2024).

### Proiectul 2 + 3

În loc de proiectele 2 și 3 separat, puteți opta pentru proiectul 2+3, un joc similar cu cel pe care îl facem la opțional, sau o aplicație cu interfață grafică și baze de date in Qt. 

Ambele propuneri folosesc librării externe, și servesc drept proiecte mult mai bune de CV și învățare mai practică a programării, în opinia mea subiectivă.

TODO: adaugă listă proiecte propuse, cerințe logică proiect, cerințe OOP minimale din cerințele proiectelor 2 și 3.

**Termen Limită Predare:** Laborator proiect saptămâna a 14-a (29 mai 2024).

### Proiectul 2

Cerințele specifice proiectului se vor afla în fișierul `Proiect2_POO_Grupa133.pdf`.

**Termen Limită Predare:** Până la vacanța de 1 Mai 2024.

### Proiectul 3

Cerințele specifice proiectului se vor afla în fișierul `Proiect3_POO_Grupa133.pdf`.

**Termen Limită Predare:** Laborator proiect saptămâna a 14-a (29 mai 2024).


## Cum să folosiți materialele

Materialele de laborator au fost scrise într-o manieră în care să fie parcurse pe rând, drept rezultat, dacă săriți peste un laborator, este posibil ca următorul să se bazeze pe cunoștințele acumulate în cadrul celui anterior, deci ordinea cronologică este ordinea cea mai bună de parcurgere pentru recapitulare și esențială pentru învățare în timpul semestrului.

Pentru a compila și rula programele din acest repository, veți avea nevoie de un compilator C++ compatibil, precum g++.

De asemenea, un IDE diferit de CodeBlocks este recomandat, puteți să vă alegeți unul din lista de mai jos, sau altul pe care îl considerați, cu funcționalități similare celor enumerate:
- Visual Studio Code
- Visual Studio
- CLion


## Contribuții

Studenții sunt încurajați să contribuie la îmbunătățirea materialelor de laborator și a cerințelor proiectelor prin sugestii, corectarea bug-urilor sau adăugarea de noi exemple relevante. Dacă aveți propuneri, vedeți secțiunea de [Contact](#section-contact) pentru a propune contribuții/schimbări.


## Licență

Materialele din acest repository sunt oferite sub licența CC BY-NC. Fișierul `LICENSE` conține mai multe detalii.


## Contact

<a name="section-contact"></a>

Pentru întrebări sau sugestii, mă puteți contacta prin intermediul platformei GitHub sau Teams.
