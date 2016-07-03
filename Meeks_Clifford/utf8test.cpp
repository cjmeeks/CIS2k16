#include <iostream>

#include "utf8string.hpp"
#include "ksu_utf8.h"
#include "ksu_unicode.h"

#define  NOBEL_CNT     112

using namespace std;

int main() {
    // Constructors are tested here
    utf8string nobel_literature[NOBEL_CNT] =
             {string("Sully Prudhomme"), // 1901
              string("Theodor Mommsen"), // 1902
              string("Bjørnstjerne Bjørnson"), // 1903
              string("Frédéric Mistral"), // 1904
              string("José Echegaray"), // 1904
              string("Henryk Sienkiewicz"), // 1905
              string("Giosuè Carducci"), // 1906
              string("Rudyard Kipling"), // 1907
              string("Rudolf Christoph Eucken"), // 1908
              string("Selma Lagerlöf"), // 1909
              string("Paul von Heyse"), // 1910
              string("Maurice Maeterlinck"), // 1911
              string("Gerhart Hauptmann"), // 1912
              string("রবীন্দ্রনাথ ঠাকুর"), // 1913 - Rabindranath Tagore
              string("Romain Rolland"), // 1915
              // No prize in 1914
              string("Verner von Heidenstam"), // 1916
              string("Karl Adolph Gjellerup"), // 1917
              string("Henrik Pontoppidan"), // 1917
              string("Carl Spitteler"), // 1919
              string("Knut Hamsun"), // 1920
              string("Anatole France"), // 1921
              string("Jacinto Benavente"), // 1922
              string("William Butler Yeats"), // 1923
              string("Władysław Reymont"), // 1924
              string("George Bernard Shaw"), // 1925
              string("Grazia Deledda"), // 1926
              string("Henri Bergson"), // 1927
              string("Sigrid Undset"), // 1928
              string("Thomas Mann"), // 1929
              string("Sinclair Lewis"), // 1930
              string("Erik Axel Karlfeldt"), // 1931
              string("John Galsworthy"), // 1932
              string("Ива́н Алексе́евич Бу́нин"), // 1933 - Ivan Bunin
              string("Luigi Pirandello"), // 1934
              string("Eugene O'Neill"), // 1936
              string("Roger Martin du Gard"), // 1937
              string("Pearl S. Buck"), // 1938
              string("Frans Eemil Sillanpää"), // 1939
              // No prize in 1940-1943
              string("Johannes Vilhelm Jensen"), // 1944
              string("Gabriela Mistral"), // 1945
              string("Hermann Hesse"), // 1946
              string("André Gide"), // 1947
              string("T. S. Eliot"), // 1948
              string("William Faulkner"), // 1949
              string("Bertrand Russell"), // 1950
              string("Pär Lagerkvist"), // 1951
              string("François Mauriac"), // 1952
              string("Winston Churchill"), // 1953
              string("Ernest Hemingway"), // 1954
              string("Halldór Laxness"), // 1955
              string("Juan Ramón Jiménez"), // 1956
              string("Albert Camus"), // 1957
              string("Бори́с Леони́дович Пастерна́к"), // 1958 - Boris Pasternak
              string("Salvatore Quasimodo"), // 1959
              string("Saint-John Perse"), // 1960
              string("Ivo Andrić"), // 1961
              string("John Steinbeck"), // 1962
              string("Γιώργος Σεφέρης"), // 1963 - Giorgos Seferis
              string("Jean-Paul Sartre"), // 1964
              string("Михаи́л Алекса́ндрович Шо́лохов"),
                    // 1965 - Mikhail Sholokhov
              string("Shmuel Yosef Agnon"), // 1966
              string("Nelly Sachs"), // 1966
              string("Miguel Ángel Asturias"), // 1967
              string("川端 康成"), // 1968 - Yasunari Kawabata
              string("Samuel Beckett"), // 1969
              string("Алекса́ндр Иса́евич Солжени́цын"),
                    // 1970 - Aleksandr Solzhenitsyn
              string("Pablo Neruda"), // 1971
              string("Heinrich Böll"), // 1972
              string("Patrick White"), // 1973
              string("Eyvind Johnson"), // 1974
              string("Harry Martinson"), // 1974
              string("Eugenio Montale"), // 1975
              string("Saul Bellow"), // 1976
              string("Vicente Aleixandre"), // 1977
              string("Isaac Bashevis Singer"), // 1978
              string("Οδυσσέας Ελύτης"), // 1979 - Odysseas Elytis
              string("Czesław Miłosz"), // 1980
              string("Elias Canetti"), // 1981
              string("Gabriel García Márquez"), // 1982
              string("William Golding"), // 1983
              string("Jaroslav Seifert"), // 1984
              string("Claude Simon"), // 1985
              string("Oluwo̩lé S̩óyinká"), // 1986 - Wole Soyinka
              string("Ио́сиф Алекса́ндрович Бро́дский"), // 1987 - Joseph Brodsky
              string("Naguib Mahfouz"), // 1988
              string("Camilo José Cela"), // 1989
              string("Octavio Paz"), // 1990
              string("Nadine Gordimer"), // 1991
              string("Derek Walcott"), // 1992
              string("Toni Morrison"), // 1993
              string("大江 健三郎"), // 1994 - Kenzaburō Ōe
              string("Seamus Heaney"), // 1995
              string("Wisława Szymborska"), // 1996
              string("Dario Fo"), // 1997
              string("José Saramago"), // 1998
              string("Günter Grass"), // 1999
              string("高行健"), // 2000 - Gao Xingjian
              string("V. S. Naipaul"), // 2001
              string("Imre Kertész"), // 2002
              string("J. M. Coetzee"), // 2003
              string("Elfriede Jelinek"), // 2004
              string("Harold Pinter"), // 2005
              string("Orhan Pamuk"), // 2006
              string("Doris Lessing"), // 2007
              string("J. M. G. Le Clézio"), // 2008
              string("Herta Müller"), // 2009
              string("Mario Vargas Llosa"), // 2010
              string("Tomas Tranströmer"), // 2011
              string("莫言"), // 2012 - Mo Yan
              string("Alice Munro"), // 2013
              string("Patrick Modiano"), // 2014
              string("Святлана Аляксандраўна Алексіевіч")
                     // 2015 - Svetlana Alexievich
             };
    utf8string    user_input;
    utf8string    input_copy;
    utf8string    test_str;
    int           i;
    string        cppstr = string("world");
    unsigned char utf8[5];

    // Uncomment what you have implemented
    // Testing assignment 
    test_str = utf8string("Hello");
    // Testing output
    cout << "test_str: " << test_str << endl;
    //
    // cout << "Testing concatenation" << endl;
    // -- Testing +
    // test_str = string("Hello") + string(" world");
    // cout << test_str << endl;
    // -- Testing +=
    // test_str += string("!");
    // cout << test_str << endl;
    // -- Testing comparison
    // if (test_str == utf8string(string("Hello world!"))) {
     //  cout << "Equal" << endl;
     //} else {
     //  cout << "Not equal" << endl;
    // }
    // -- Testing input
     cout << "Please enter anything, preferably with multi-byte characters:"
          << endl;
     cin >> cppstr;
     cout << "You entered: " << cppstr << endl;
    // -- Big test
    (void)ksu_codepoint_to_utf8(ksu_hex_to_codepoint("1f60a"), utf8);
    for (i = 0; i < NOBEL_CNT; i++) {
       cout << nobel_literature[i];
       cout << " " << nobel_literature[i].length();
       // cout << " " << nobel_literature[i].upper();
       // cout << " " << nobel_literature[i].lower();
       // cout << " " << nobel_literature[i].unaccent();
       // cout << " " << nobel_literature[i].reverse();
       // cout << " " << nobel_literature[i].replace(utf8string("o"),
       //                                            utf8string((char *)utf8));
       cout << endl;
    }
    return 0;
}

