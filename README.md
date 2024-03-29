# Magazin electronic

## Proiect realizat de Matei Ovidiu, Lungu Vanessa, Manole Alexandru, Mihai Mario si Meraj Andri
### ASE - Cibernetica economica - Anul II - Sem I

## Să se realizeze o aplicație de tip consolă în C++ care să utilizeze principiile POO pentru realizarea funcționalităților unui magazin electronic.

Cerințe:
- introducerea a două tipuri de utilizatori: magazin și client (Ovidiu)

- cerințe specifice magazinului:
  - adăugarea de produse **(Ovidiu)**
  - editarea de produse **(Vanessa)**
  - ștergerea de produse **(Vanessa)**
  - prelucrarea comenzilor **(Ovidiu si Max)**
  - realizarea unui raport (într-un fișier text) cu privire la comenzile primite **(Ovidiu)**

- cerințe specifice clientului:
  - vizualizarea produselor din magazin **(Ovidiu)**
  - selectarea produselor dorite și introducerea acestora într-un coș electronic **(Mario)**
  - scoaterea de produse din coșul electronic **(Ovidiu)**
  - completarea datelor personale ale clientului **(Ovidiu)**
  - trimiterea comenzii cu produsele din coșul electronic. Se vor furniza și datele clientului (de ex. nume, adresa, etc.) **(Ovidiu si Andri)**
  - realizarea unui raport (într-un fișier text) cu privire la comanda trimisă **(Ovidiu)**

- toate funcționalitățile vor fi puse la dispoziție prin intermediul unei interfețe de tip meniu realizat în consolă **(Ovidiu)**
- la deschiderea aplicației se va interoga tipul de utilizator cu care se intră și în funcție de utilizatorul ales (magazin sau client) se va pune la dispoziție meniul specific **(Ovidiu)**

Cerințe tehnice:
- să se realizeze cel puțin 5 clase **(Toti)**
- să se realizeze cel puțin o ierarhie de clase care să implementeze principiile moștenirii (cel puțin 3 clase utilizate în această ierarhie pentru a se evidenția beneficiile moștenirii) **(Toti)**
- să se realizeze cel puțin o clasă de tip interfață, iar referința la această interfață să fie folosită în program când vor fi referite obiectele copil. Să se folosească polimorfismul. **(Ovidiu)**
- atributele să fie protejate prin mecanismul de încapsulare, iar accesul la acestea să se facă prin getteri și setteri (metode accesor) **(Toti)**
- să se realizeze constructori default și cu parametri pentru clasele care conțin entități. Să se facă validarea parametrilor. Să se realizeze destructorul, constructorul de copiere și supraîncărcarea operatorului egal pentru aceste clase. **(Toti)**
- să se facă în proiect cel puțin 3 supraîncărcări de operatori (diferiți de operatorul =, << și >>) **(Vanessa)**
- să se stocheze persistent în fișiere binare produsele existente în magazin și comenzile trimise de clienți **(Ovidiu si Max)**
- rapoartele menționate în cerințele de funcționalitate ale aplicației vor fi salvate în fișiere text **(Ovidiu)**
- să se folosească cel puțin o clasă din STL pentru stocarea unei structuri de date (ex. listă, coadă sau stivă etc) **(Ovidiu)**
