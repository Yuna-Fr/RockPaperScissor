#include <iostream>
#include <random>

void Title();
void LaunchGame();
void AskPlayerChoice();
const char* ConvertChoice(int);

char input;

int userPoints = 0;
int userChoice = 0;

int botPoints = 0;
int botChoice = 0;

int main()
{
    Title();
    LaunchGame();

    return 0;
}

void LaunchGame()
{
    //Player's turn
    AskPlayerChoice();
    std::cout << "\n Vous avez choisis " << ConvertChoice(userChoice);

    //Bot's turn
    std::random_device rd;
    std::srand(rd());
    botChoice = 1 + (rand() % 3);
    std::cout << "\n Bot a choisi " << ConvertChoice(botChoice);

    //Verdict
    if (userChoice == botChoice)
        std::cout << "\n\n EGALITE !";
    else
    {
        if (userChoice + 1 == 4)
            userChoice = 0;

        if (userChoice + 1 == botChoice)
        {
            std::cout << "\n\n PERDU ! \n Bot gagne 1 point.";
            botPoints++;
        }
        else
        {
            std::cout << "\n\n GAGNE ! \n Vous gagnez 1 point !";
            userPoints++;
        }
    }

    std::cout << "\n\nVous : " << userPoints << " pts";
    std::cout << "\nBot : " << botPoints << " pts\n";
    
    LaunchGame();
}

void AskPlayerChoice()
{
    std::cout << "\n Entrer votre choix : 1 = Pierre, 2 = Feuille, 3 = Ciseaux \n\n";
    std::cin >> userChoice;//check if invalid

    if (std::cin.fail() || (userChoice != 1 && userChoice != 2 && userChoice != 3))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Merci d'entrer un chiffre valide entre 1 (Pierre), 2 (Feuille) ou 3 (Ciseaux)";
        AskPlayerChoice();
    }
}

const char* ConvertChoice(int entry)
{
    switch (entry)
    {
        case 1:
            return "pierre";

        case 2:
            return "feuille";

        case 3:
            return "ciseaux";

        default:
            return "invalid";
    };
}

void Title()
{
    std::cout << " ____  _                      _____          _ _ _         ____ _\n";
    std::cout << "|  _ \\(_) ___ _ __ _ __ ___  | ___ |__ _   _(_) | | ___   / ___(_)___  ___  __ _ _   ___  __\n";
    std::cout << "| |_) | |/ _ \\ '__| '__/ _ \\ | |_ / _ \\ | | | | | |/ _ \\ | |   | / __|/ _ \\/ _` | | | \\ \\/ /\n";
    std::cout << "|  __/| |  __/ |  | | |  __/ |  _ | __/ |_| | | | |  __/ | |___| \\__ \\  __/ (_| | |_| |>  < \n";
    std::cout << "|_|   |_|\\___|_|  |_|  \\___| |_ | \\___|\\__,_|_|_|_|\\___|  \\____|_|___/\\___|\\__,_|\\__,_/_/\\_\\\n";
}
