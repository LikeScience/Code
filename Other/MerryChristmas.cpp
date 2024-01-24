#include <iostream>
#include <windows.h>
using std::cout;
using std::endl;

int main(int argc, char** argv) {

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                                By Giulio N. a.k.a. JuliusNixi - MERRY CHRISTMAS                                             //
    ////////////////////////////EXTRA-UNIVERSITY PROJECT CARRIED OUT IN THE FIRST YEAR (WINTER 2020) OF STUDY TO DEEPEN C++//////////////////////////
    ///////////////////////////////////////////////////////////THIS ARE THE DEFAULT SETTINGS/////////////////////////////////////////////////////////
    /////////////////////////////////YOU CAN CHANGE AS DESIRED AND RECOMPILE OR YOU CAN EDIT THEM BY PASSING THE CORRESPONDING ARGS//////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool PRINT_TREE = true;
    bool PRINT_MERRYCHRISTMAS = true;

    bool COLORS = true;

    bool CHRISTMAS_BALLS = true;
    char CHRISTMAS_BALLS_CHAR = 'O';

    int SIZE = 20U;

    char TREE_CHAR = '*';
    char TRONK_CHAR = '|';

    bool PRINT_SIGNATURE = true;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////THE TREE IS CONFIGURABLE HOW COOL IS THAT!/////////////////////////////////////////////////
    /////////////////////////////////////THE SIZE (LINES) MINIMUM IS 6 BECAUSE OTHERWISE THE PROPORTIONS DO NOT WORK//////////////////////////////////
    /////////////////////THIS SOFTWARE WORKS ONLY ON WINDOWS BECAUSE THE COLORS ARE IMPLEMENTED THROUGH WINDOWS.H NOT PRESENT ON LINUX////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    //If the arguments are greater than 1 I process them.
    if (argc > 1){

        //If the arguments are other than 10, I show the help message. 9 args + 1 (filename).
       if (argc != 9 + 1) {
            cout << endl << "\t\t\t\tBy Giulio N. a.k.a. JuliusNixi - MERRY CHRISTMAS " << endl << endl;
            cout << "Usage: Enter all of the following arguments, interspersed with a space and with this format: " << endl << endl;
            cout << "PRINT_TREE: 1/0 (1 means yes, 0 means no)." << endl;
            cout << "PRINT_MERRYCHRISTMAS: 1/0." << endl;
            cout << "COLORS: 1/0." << endl;
            cout << "CHRISTMAS_BALLS: 1/0." << endl;
            cout << "CHRISTMAS_BALLS_CHAR: One single character. Be careful not to use shell reserved characters like '|'' or '>'." << endl;
            cout << "SIZE: Positive integer greater than or equal to 6." << endl;
            cout << "TREE_CHAR: One single character. Be careful not to use shell reserved characters like '|'' or '>'." << endl;
            cout << "TRONK_CHAR: One single character. Be careful not to use shell reserved characters like '|'' or '>'." << endl;
            cout << "PRINT_SIGNATURE: 1/0." << endl << endl;
            cout << "Example: MerryChristmas.exe 1 1 1 1 X 10 + - 0" << endl << endl;
            cout << "Alternatively, you can call the software with the default parameters if NO arguments are passed." << endl << endl;
            return -1;
        }

       //IT
       //ARGV è una matrice contenente gli argomenti ricevuti come array di caratteri.
       //Accedo al singolo array usando l'operatore di deferenziazione (*).
       //Sottraggo 48 che è la codifica ASCII di 0 per avere la conversione in INT e poi implicitamente in BOOL.
       //EN
       //ARGV is an array containing the arguments received as an array of characters.
       //I access the single array using the deferencing operator (*).
       //I subtract 48 which is the ASCII encoding of 0 to have the conversion in INT and then implicitly in BOOL.
        PRINT_TREE = *argv[1] - 48;
        PRINT_MERRYCHRISTMAS = *argv[2] - 48;

        COLORS = *argv[3] - 48;

        CHRISTMAS_BALLS = *argv[4] - 48;
        CHRISTMAS_BALLS_CHAR = (char)*argv[5];

       //IT
       //L'argomento SIZE può essere un numero composto da più cifre. Va quindi trattato come stringa.
       //Lo copio dentro l'array str con strcpy() e lo converto in intero grazie alla funzione atoi().
       //EN
       //The SIZE argument can be a multi-digit number. It should therefore be treated as a string.
       //I copy it inside the str array with strcpy() and convert it to integer thanks to the atoi() function.
        char str[20];
        strcpy(str, argv[6]);
        SIZE = atoi(str);

        TREE_CHAR = (char)*argv[7];
        TRONK_CHAR = (char)*argv[8];

        PRINT_SIGNATURE = *argv[9] - 48;

    }

    //To color the output. Initializing.
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << endl;

    //I print the tree if PRINT_TREE is true.
    if (PRINT_TREE) {

        //Check on the rows so that they are >= 6.
        if (SIZE < 6) {
            cout << "I like small trees (sounds bad, I know), but this is just too much! :P" << endl;
            return -1;
        }

        //I change the color to green if COLOR is true.
        if (COLORS)
            SetConsoleTextAttribute(hConsole, 10);

        //Spacing constant to center the tree.
        unsigned spacing_constant = 22;

        //Utility variables to print the tree (top).
        unsigned tree_spaces = SIZE + spacing_constant;
        unsigned tree_chars = 2; //Tree tip composed of two characters, must be even numbered so as not to cause problems when printing the tree trunk.

        //Utility variables to print the trunk (lower part).
        unsigned trunk_lines = SIZE >= 10 ? SIZE / 10 : 1; //How many trunk rows to print?
        unsigned trunk_spaces = tree_chars * SIZE / 4 + spacing_constant;
        unsigned trunk_chars = tree_chars * SIZE / 2 + (SIZE % 2 == 0 ? 2 : 3);

        SIZE++; //I correct by adding a line because to print the trunk I will skip the last loop.

        //Loop over the rows.
        for (int i = 0; i < SIZE; i++) {

            //If we're on the second to last line, I start printing the tree trunk.
            if (i + 1 == SIZE) {

                //I set the trunk color to brownish for trunk.
                if (COLORS){
                    SetConsoleTextAttribute(hConsole, 6);
                }

                //Loop over the rows (only those in the lower part of the tree).
                for (int j = 0; j < trunk_lines; j++) {

                    //I print out the spaces in the trunk.
                    for (int z = 0; z < trunk_spaces; z++)
                        cout << " ";

                    //I print the trunk characters.
                    for (int z = 0; z < trunk_chars; z++)
                        cout << TRONK_CHAR;

                    cout << endl;

                }

                //I break the loop (it would have ended on the next iteration anyway).
                break;

            }

            //I'm going to print the tree spaces.
            for (int j = tree_spaces; j > 0; j--)
                cout << " ";

            //I print the tree characters.
            for (int j = 0; j < tree_chars; j++) {

                //If CHRISTMAS_BALLS is true then I draw a random number between 0 and 1 to see whether or not to put a Christmas Ball.
                if (CHRISTMAS_BALLS && rand() % 2 == 1) {

                    //I now set the console color to a random color between 1 and 15.
                    SetConsoleTextAttribute(hConsole, rand() % 15 + 1);
                    cout << CHRISTMAS_BALLS_CHAR;

                    //I reset the console color to default or green.
                    if (COLORS)
                        SetConsoleTextAttribute(hConsole, 10);
                    else
                        SetConsoleTextAttribute(hConsole, 7);

                }else
                    cout << TREE_CHAR;
            }

            //I decrease the spaces in the tree to be printed on the next iteration.
            tree_spaces--;
            //I increase the chars in the tree to be printed on the next iteration.
            tree_chars += 2;

            //After I finish printing the tree line I go to the end of the line.
            cout << endl;

        }

    }

    //I set the color to red for the Merry Christmas text.
    if (COLORS)
        SetConsoleTextAttribute(hConsole, 4);

    //I print MerryChristmas if true.
    if (PRINT_MERRYCHRISTMAS) {

        cout << "  __  __  ___  ___  ___ __   __   ___  _  _  ___  ___  ___  _____  __  __    _    ___ " << endl;
        cout << " |  \\/  || __|| _ \\| _ \\\\ \\ / /  / __|| || || _ \\|_ _|/ __||_   _||  \\/  |  /_\\  / __|"
             << endl;
        cout << " | |\\/| || _| |   /|   / \\ V /  | (__ | __ ||   / | | \\__ \\  | |  | |\\/| | / _ \\ \\__ \\"
             << endl;
        cout << " |_|  |_||___||_|_\\|_|_\\  |_|    \\___||_||_||_|_\\|___||___/  |_|  |_|  |_|/_/ \\_\\|___/" << endl;

    }

    //I print the signature in blue.
    if (PRINT_SIGNATURE){
        cout << endl << endl;
        SetConsoleTextAttribute(hConsole, 1);
        cout << "By Giulio N. a.k.a. JuliusNixi" << endl;
    }

    //If I used colors, I reset the console color to the default.
    if (COLORS || CHRISTMAS_BALLS || PRINT_SIGNATURE)
        SetConsoleTextAttribute(hConsole, 7);

    //If the arguments are null, argc == 1 (only filename), the user maybe double clicked the file, so we call a system PAUSE to wait an input.
    if (argc == 1){
    	cout << endl;
    	system("PAUSE");
    }

    return 0;

}
