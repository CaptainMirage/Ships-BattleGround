#include <iostream>
// #include <cstdlib>
using namespace std;

/* Name: ShipsBattle (c++ Edition)
 * Version: Beta release
 * Developer: Captain Mirage
 * idea: the good old times
 * Description {
 *      a cool good version of the ShipsBattle that was popular back in the days,
 *      it's still in progress but if you have any ideas feel free to share
 *  };
 */



int main() {
    int columnSIZE = 6;
    int rowSIZE = 6;
    // put "1" to indicate there is a ship.
    int Ships[6][6] = {
            { 1, 0, 0, 0, 1, 0 },
            { 0, 0, 0, 1, 0, 0 },
            { 0, 0, 1, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 1, 1, 0 },
            { 0, 1, 0, 0, 0, 1 }
    };

    int hits = 0;
    int numberOfTurns = 0;
    int numOfShips = 0;

    for (int i = 0; i < rowSIZE; i++)
        for (int j = 0; j < columnSIZE; j++) {
            if (Ships[i][j] == 1) {
                numOfShips++;
            }
        }
    printf("-==========[ There are %i Ships ]==========-\n", numOfShips);


    while (hits < numOfShips) {
        int column;
        int row;

        cout << "Select Coordinates...";
        cout << "\n-------------\n";

        cout << "Choose a row number between 1 and " << rowSIZE << " :";
        cin >> row;

        cout << "Choose a column number between 1 and " << columnSIZE << " :";
        cin >> column;


        cout << "_____________";
        // NOTE: Checks if there is any ships nearby the place targeted
        if (Ships[row - 1][column - 1 + 1] == 1) {
            cout << "\n-========[ Ship nearby! ]========-";
        }

        else if (Ships[row - 1][column - 1 - 1] == 1) {
            cout << "\n-========[ Ship nearby! ]========-";
        }

        else if (Ships[row - 1 + 1][column - 1] == 1) {
            cout << "\n-========[ Ship nearby! ]========-";
        }

        else if (Ships[row - 1 - 1][column - 1] == 1) {
            cout << "\n-========[ Ship nearby! ]========-";
        }

        // NOTE: Checks if a ship exists in those coordinates
        if (Ships[row - 1][column - 1]) {
            Ships[row - 1][column - 1] = 0;
            hits++;

            cout << "\nHit! " << (numOfShips-hits) << " ships left.\n";
            cout << "--------------------\n";

        } else {
            cout << "\nMissed\n";
            cout << "-----------------\n";

        }
        numberOfTurns++;
    }

    cout << "-=========[ Victory! ]=========-\n";
    cout << "You won in " << numberOfTurns << " turns";

    return 101011;
}
