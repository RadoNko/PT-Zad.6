/*
 Meno a priezvisko:
 
 POKYNY:
 (1)  Subor premenujte na Priezvisko_Meno_ID_du07.cpp (pouzite vase udaje bez diakritiky).
 (2)  Implementujte funkcie tak, aby splnali popis pri ich deklaraciach.
 (3)  Cela implementacia musi byt v tomto jednom subore.
 (4)  Odovzdajte len tento (spravne premenovany) zdrojovy subor.
 (5)  Program musi byt kompilovatelny.
 (6)  Globalne a staticke premenne su zakazane.
 (7)  V ziadnom pripade nemente deklaracie funkcii, ktore mate za ulohu naprogramovat
 (nemente nazvy, navratove hodnoty ani typ a pocet parametrov v zadanych funkciach).
 Nemente implementacie zadanych datovych typov, ani implementacie hotovych pomocnych funkcii
 (ak nie je v zadani ulohy uvedene inak).
 (8)  V pripade potreby mozete kod doplnit o dalsie pomocne funkcie alebo struktury.
 (9)  Vase riesenie otestujte (vo funkcii 'main' a pomocou doplnenych pomocnych funkcii alebo struktur).
 Testovaci kod ale nebude hodnoteny.
 (10) Funkcia 'main' musi byt v zdrojovom kode posledna.
 */

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
 Vytvori frontu, ktora obsahuje rovnake prvky ako vstupny zoznam, ale v opacnom poradi.
 Obsah vstupneho zoznamu nemeni.
 
 Implementujte pomocou reverzneho iteratora.
 
 PARAMETER:
 [in] data - zoznam prvkov, ktore funkcia nakopiruje do vytvorenej fronty.
 
 NAVRATOVA HODNOTA:
 Nova fronta, obsahujuca kopie prvkov vstupneho zoznamu v opacnom poradi
 */

queue<int> reverse(const list<int> & data) noexcept {
    // TODO
    queue<int>rev;
    for (auto i = data.rbegin(); i!=data.rend(); i++) {
        rev.push(*i);
    }
    return rev; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
 Preusporiada prvky vo fronte tak, ze budu v opacnom poradi.
 
 Implementujte pomocou zasobnika (algoritmus ulozi prvky z fronty do zasobnika a potom zo zasobnika naspat do fronty).
 
 PARAMETER:
 [in, out] data - fronta, v ktorej funkcia zmeni poradie prvkov na opacne
 */

void reverse(queue<int> & data) noexcept {
    // TODO
    stack<int>tmp;
    while (!data.empty()) {
        tmp.push(data.front());
        data.pop();
    }
    while (!tmp.empty()) {
        data.push(tmp.top());
        tmp.pop();
    }
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
 Vytvori vektor, ktoreho prvkami su vektory cisiel typu 'int'.
 
 PARAMETRE:
 [in] size1 - pocet prvkov hlavneho vektora (pocet vnorenych vektorov)
 [in] size2 - pocet prvkov kazdeho vektora, ktory je prvkom hlavneho vektora (vnorene vektory budu rovnako dlhe, ich dlzka bude 'size2')
 [in] value - hodnota kazdeho celeho cisla vo vektore vektorov
 
 NAVRATOVA HODNOTA:
 Vektor, ktoreho prvkami su vektory cisiel (pocet jeho prvkov je 'size1').
 Vnorene vektory su rovnako dlhe (pocty ich prvkov su 'size2').
 Vsetky cisla vo vektore vektorov maju hodnotu 'value'.
 
 PRIKLAD:
 vstup:
 size1 = 2, size2 = 5, value = 10
 vystup:
 { { 10, 10, 10, 10, 10 }, {10, 10, 10, 10, 10} }
 */

vector<vector<int>> create2dVector(const size_t size1, const size_t size2, const int value) noexcept {
    // TODO
    vector<vector<int>> tmp(size1);
    for (int i = 0; i < size1; i++) {
        tmp[i].assign(size2, value);
    }
    return tmp; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
 Vrati textovy retacec, ktory vznikne zretazenim textu 'text', medzery  a cisla 'number'.
 
 PARAMETRE:
 [in] text - textovy retazec
 [in] number - cislo
 
 NAVRATOVA HODNOTA:
 Novy textovy retazec, ktory vznikne zretazenim 'text', jednej medzery a 'number'
 (cislo 'number' je skonvertovane na textovy retazec).
 
 PRIKLADY:
 1. priklad:
 text: "abc", number: 10, vystup: "abc 10"
 2. priklad:
 text: " abc ", number: 10, vystup: " abc  10"
 3. priklad:
 text: "", number: -10, vystup: " -10"
 */

string connectWithSpace(const string & text, const int number) noexcept {
    // TODO
   
    return text+" "+to_string(number); // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
 Precita cisla zo vstupneho textoveho prudu a vrati ich sucet.
 Ak sa vo vstupnom prude vyskytne text, ktory sa neda skonvertovat na cislo,
 tak citanie skonci a vrati sucet precitanych cisiel (neskusa hladat dalsie cisla).
 Pred, medzi a za cislami moze byt lubovolny pocet bielych znakov.
 
 PARAMETER:
 [in] text - vstupny textovy prud
 
 NAVRATOVA HODNOTA:
 Sucet precitanych cisiel (do konca, alebo po vyskyt chyby pri citani alebo konvertovani textu na cislo)
 
 PRIKLADY:
 text: "10 20 30 10", vystup: 70
 text: " 10   20 30 10 ", vystup: 70
 text: "10 a 20", vystup: 10 (pri konverzii "a" na cislo nastala chyba, funkcia vratila sucet cisiel po vyskyt prvej chyby citania/konverzie)
 text: "", vystup: 0
 */

int sum(istringstream & text) noexcept {
    // TODO
    
    int val{},sum{};
    while (text >> val) {
        sum+=val;
    }
    return sum; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
 Prelozi zoznam slov 'sentence' z jedneho jazyka do druheho pomocou slovnika 'translator' a vrati prelozeny zoznam slov.
 Pri prekladani zachova vstupne poradie slov.
 Ak sa v slovniku 'translator' nenachadza preklad, tak do vystupneho zoznamu zapise namiesto prekladu otaznik.
 Pri preklade sa rozlisuju male a velke pismena, cize pri hladani prekladu netreba konvertovat velke pismena na male, alebo opacne.
 
 PARAMETERE:
 [in] translator - mapuje slova zo vstupneho jazyka do vystupneho jazyka
 [in] sentence - zoznam slov vo vstupnom jazyku
 
 NAVRATOVA HODNOTA:
 Novy zoznam slov prelozenych do vystupneho jazyka, v poradi, v ktorom boli v 'sentence'.
 Ak slovnik 'translator' neobsahuje preklad slova, tak je vo vystupnom zozname namiesto prekladu otaznik.
 
 PRIKLADY:
 Vo vsetkych prikladoch predpokladajme obsah prekladoveho slovnika:
 translator: {
 "read" -> "citat",
 "write" -> "pisat",
 "book" -> "kniha",
 "I" -> "ja",
 "you" -> "ty",
 "he" -> "on",
 "she" -> "ona",
 "it" -> "ono"
 "a" -> "",
 "an" -> "",
 "the" -> ""
 }
 1. priklad:
 sentence: { "I", "read", "a", "book"}, vystup: { "ja", "citat", "", "kniha" }
 2. priklad:
 sentence: { "I", "am", "reading", "a", "book" }, vystup: { "ja", "?", "?", "", "kniha"}
 3. priklad:
 sentence: { "He", "reads", "a", "book" }, vystup: { "?", "?", "", "kniha"}, poznamka: neprelozil "He", pretoze v slovniku je len "he"
 */

list<string> translate(const map<string, string> & translator, const list<string> & sentence) noexcept {
    // TODO
    list<string>tmp;
    for (auto  i = sentence.begin(); i!=sentence.end(); i++) {
        auto result_iter = translator.find(*i);
        if (result_iter!=translator.end()) {
            tmp.push_back(result_iter->second);
        }
        else tmp.push_back("?");
    }
    return tmp; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
 Zisti, ci su vo vstupnom textovom retazci spravne sparovane zatvorky.
 Ak ano, vrati 'true', inak vrati 'false'.
 Testuje nasledujuce typy zatvoriek: ( ) { } [ ] < >
 
 V implementacii pouzite na ukladanie otvaracich zatvoriek zasobnik
 a porovnavajte zatvaracie zatvorky s poslednou otvaracou zatvorkou (na vrchole zasobnika).
 
 PARAMETER:
 [in] mathExpression - textovy retazec, v ktorom funkcia testuje spravnost sparovania zatvoriek
 
 NAVRATOVA HODNOTA:
 Ak su zatvorky spravne sparovane vrati 'true',
 inak vrati 'false'.
 
 PRIKLADY:
 vstup: "ab - (c< d > 1) + {[23 ( [ 45] ) 6] 7} 8 ", vystup: 'true'
 vstup: "(", vystup: 'false'
 vstup: "())", vystup: 'false'
 vstup: "{ >", vystup: 'false'
 */

bool areParenthesisPaired(const string & mathExpression) noexcept {
    // TODO
    stack<char>stk;
    for (const char&c : mathExpression) {
        if (c == '(' || c == '[' || c == '{' || c == '<') {
            stk.push(c);
        }
        switch (c) {
            case ')':
                if (stk.empty() || stk.top()!='('){
                    return false;
                }
                stk.pop();
                break;
            case '>':
                if (stk.empty() || stk.top()!='<'){
                    return false;
                }
                stk.pop();
                break;
            case ']':
                if (stk.empty() || stk.top()!='['){
                    return false;
                }
                stk.pop();
                break;
            case '}':
                if (stk.empty() || stk.top()!='{'){
                    return false;
                }
                stk.pop();
                break;
            default:
                break;
        }
    }
    if (stk.empty()) {
        return true;
    }
    else return false;
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
 Zavola funkciu 'function', s parametrami 'parameter1' a 'parameter2' a vrati jej vysledok.
 
 PARAMETRE:
 [in] function   - funkcia, ktoru funkcia 'execute' zavola
 [in] parameter1 - pri volani 'function' bude pouzity ako 1. parameter
 [in] parameter2 - pri volani 'function' bude pouzity ako 2. parameter
 
 NAVRATOVA HODNOTA:
 Vysledok volania 'function(parameter1, parameter2)'
 
 Funkcie 'multiply' a 'maxValue' su priklady funkcii, ktore mozu byt pouzite ako parameter funkcie 'execute'.
 
 PRIKLADY:
 1. priklad:
 volanie: execute(multiply, 20, 50) alebo execute(&multiply, 20, 50)
 vystup: 1000
 2. priklad:
 volanie: execute(maxValue, 20, 50) alebo execute(&maxValue, 20, 50)
 vystup: 50
 3. priklad:
 volanie: execute([](int a, int b)->int { return a - b; }, 20, 50)
 vystup: -30
 */

int multiply(int a, int b) noexcept {
    return a * b;
}

int maxValue(int a, int b) noexcept {
    if(a >= b) {
        return a;
    }
    else {
        return b;
    }
}

int execute(int (*function)(int, int), int parameter1, int parameter2) {
    // TODO
    return function(parameter1,parameter2); // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
 Zavola funkciu 'function', ktora je vstupnym parametrom.
 Vrati hodnotu podla toho, ci a aku vynimku 'function' vyhodi.
 
 PARAMETER:
 [in] function - funkcia, ktora bude zavolana a testovana ci a aku vynimku vyhodi
 
 NAVRATOVA HODNOTA:
 ExceptionType::NO_EXCEPTION - ak 'function' nevyhodi ziadnu vynimku
 ExceptionType::INVALID_ARGUMENT - ak 'function' vyhodi vynimku typu 'std::invalid_argument'
 ExceptionType::BAD_ALLOC - ak 'function' vyhodi vynimku typu 'std::bad_alloc'
 ExceptionType::UNKNOWN_EXCEPTION - ak 'function' vyhodi iny typ vynimky
 
 Funkcie: 'doNotThrow', 'throwInvalidArgument', 'throwBadAlloc', 'throwOutOfRange' mozete pouzit pre testovanie.
 */

void doNotThrow() noexcept {
}

void throwInvalidArgument() {
    throw std::invalid_argument("popis vynimky"); // konstruktor vynimka ma parameter
}

void throwBadAlloc() {
    throw std::bad_alloc(); // konstruktor vynimky nema parameter
}

void throwOutOfRange() {
    throw std::out_of_range("popis vynimky");
}

enum class ExceptionType {
    NO_EXCEPTION,
    INVALID_ARGUMENT,
    BAD_ALLOC,
    UNKNOWN_EXCEPTION
};

ExceptionType throwsException(void (*function)()) noexcept {
    // TODO
    try {
        function();
    }
    catch (const std::bad_alloc& e) {
        return ExceptionType::BAD_ALLOC;
    }
    catch(const std::invalid_argument& e){
        return ExceptionType::INVALID_ARGUMENT;
    }
    catch(const std::exception& e){
        return ExceptionType::UNKNOWN_EXCEPTION;
    }

    return ExceptionType::NO_EXCEPTION; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
 Vytvori zoznam, ktoreho jeden prvok bude mat hodnotu 1, ostatne prvky hodnotu 0.
 Zoznam bude mat 'length' prvkov.
 Prvok s indexom 'indexOfOne' bude mat hodnotu 1, ostatne prvky hodnotu 0.
 V pripade chybnych vstupnych parametrov funkcia vyhodi vynimku.
 
 PARAMETRE:
 [in] length - pocet prvkov vytvoreneho zoznamu
 [in] indexOfOne - index prvku, ktory bude mat hodnotu 1
 
 NAVRATOVA HODNOTA:
 Zoznam, ktory obsahuje jednu 1 (prvok s indexom 'indexOfOne') a ostatne jeho prvky maju hodnotu 0.
 Prvy prvok ma index nula.
 
 VYNIMKA:
 Ak 'indexOfOne' >= 'length', tak funkcia vyhodi vynimku typu 'IndexOutOfRangeException',
 ktora nesie informacie o pozadovanej dlzke zoznamu a indexe kde mala byt hodnota 1.
 
 PRIKLADY:
 1. priklad
 vstup: length = 5, indexOfOne = 0
 vystup: {1, 0, 0, 0, 0}
 2. priklad
 vstup: length = 5, indexOfOne = 1
 vystup: {0, 1, 0, 0, 0}
 3. priklad
 vstup: length = 5, indexOfOne = 5
 vyhodi vynimku, ktorej metoda 'getLength' vrati 5 a 'getIndex' vrati 5
 4. priklad
 vstup: length = 5, indexOfOne = 10
 vyhodi vynimku, ktorej metoda 'getLength' vrati 5 a 'getIndex' vrati 10
 5. priklad
 vstup: count = 0, indexOfOne = 0
 vyhodi vynimku, ktorej metoda 'getLength' vrati 0 a 'getIndex' vrati 0
 */

class IndexOutOfRangeException {
private:
    const size_t length;
    const size_t index;
public:
    IndexOutOfRangeException(size_t length, size_t index) noexcept
    : length(length)
    , index(index) {
    }
    
    size_t getLength() const noexcept {
        return length;
    }
    
    size_t getIndex() const noexcept {
        return index;
    }
    
    string what() const noexcept {
        return "index out of range: " + to_string(index) + " >= " + to_string(length);
    }
};

list<int> createList(const list<int>::size_type length, const list<int>::size_type indexOfOne){
    // TODO
    list<int>tmp;
    int count{};
    try {
        if (indexOfOne >= length) {
            throw IndexOutOfRangeException(length,indexOfOne);
        }
        else{
            for (list<int>::size_type i = 0; i < length; i++) {
                if (count == indexOfOne) {
                    tmp.push_back(1);
                }
                else tmp.push_back(0);
                count++;
            }
        }
    } catch (IndexOutOfRangeException e) {
        cout << e.what() << endl;
    }
    
    
    
    
    
    return tmp; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne testovacie funkcie a struktury

int main() {
    
    // tu mozete doplnit testovaci kod
//    list<int>list_test ={1,2,3,4,5};
//    queue<int>test = reverse(list_test);
//    reverse(test);
//   vector<vector<int>>t_vect = create2dVector(1, 5, 10);
//    string s = connectWithSpace("", -52132);
    

    
//    const map<string,string> translator ={
//        make_pair("read", "citat"),
//        make_pair("write", "pisat"),
//        make_pair("book", "kniha"),
//        make_pair("I", "ja"),
//        make_pair("you", "ty"),
//        make_pair("he", "on"),
//        make_pair("she", "ona"),
//        make_pair("it", "ono"),
//        make_pair("a", ""),
//        make_pair("an", ""),
//        make_pair("the", "")
//    };
//    list<string>l=translate(translator, { "I", "read", "a", "book"});
//    for (auto i = l.begin(); i!= l.end(); i++) {
//        cout<<*i<<" ";
//    }
//    cout<<endl;
//    istringstream veta{"10 a 20"};
//    cout<< sum(veta) << endl;
    
    string s2 = """ab - (c< d > 1) + {[23 ( [ 45] ) 6] 7} 8 """;
    cout << (areParenthesisPaired(s2) ? "True":"False") <<endl;
    
//    cout<< execute([](int a, int b)->int { return a - b; }, 20, 50) << endl;
    
    
//    ExceptionType e =throwsException(doNotThrow);
    
//    const list<int>::size_type a = 10;
//    const list<int>::size_type b = 12;
//    list<int>test_list = createList(a, b);
//    for (auto i = test_list.begin(); i!=test_list.end(); i++) {
//        cout<< *i << " ";
//    }
//    cout<<endl;
    return 0;
}
