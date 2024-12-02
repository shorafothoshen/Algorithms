#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class CurrentValidID
{
public:
    int year;
    string branch;
    int totalVoters;
};

class Candidate
{
public:
    int cid;
    string cname;
    int votes;
};

class ElectionSystem
{
private:
    CurrentValidID currentValidID; // object of Valid_ID
    Candidate candidateArray[20];  // array for number of candidates store in Candidate class
    int numberOfCandidates;
    string voterVotes;

public:
    ElectionSystem()
    {
        voterVotes.resize(200, '0'); // calling constructor to initialize 200 size string that fill with 0
    }

    int extractYear(string userID)
    {
        return stoi(userID.substr(0, 4));
    }

    int extractNID_No(string userID)
    {
        return stoi(userID.substr(9, 5));
    }

    bool checkBranchCode(string userID)
    {
        string branchCode = userID.substr(4, 5);
        return branchCode == currentValidID.branch;
    }

    bool authenticateAdmin()
    {
        string username, password;
        cout << "\nEnter username: ";
        cin >> username;
        if (username != "admin")
        {
            return false;
        }
        else
        {
            cout << "Enter Password: ";
            cin >> password;
            return password == "admin";
        }
    }

    void banID()
    {
        // Open a file called "Banned.txt" for writing
        ofstream bannedFile("Banned.txt");

        // Print a message indicating the creation of "Banned.txt"
        cout << "\nCreating Banned.txt..." << endl;

        // Print instructions for banning IDs and exiting the function
        cout << "Just Enter the last digit of NID to ban\nPress 0 to exit... ";

        // Variable to store user input
        int input;

        // Infinite loop to continuously take user input until 0 is entered
        while (true)
        {
            // Prompt the user to enter a number
            cout << "\nEnter Number: ";
            cin >> input;

            // If the user enters 0, exit the loop and end the function
            if (input == 0)
            {
                break;
            }

            // Mark the corresponding voter ID as banned by setting it to '$' in the voterVotes array
            voterVotes[input - 1] = '$';

            // Write the banned ID to the "Banned.txt" file
            bannedFile << input << endl;
        }

        // Close the "Banned.txt" file
        bannedFile.close();

        // Print a message indicating successful creation of "Banned.txt"
        cout << "Created Successfully" << endl;
    }

    void createCandidateFiles()
    {
        cout << "\nCreating candidate files..." << endl;
        for (int i = 0; i < numberOfCandidates; i++)
        {
            string filename = "candidate" + to_string(i + 1) + ".txt";
            ofstream candidateFile(filename);
            candidateFile << "0\n"
                          << candidateArray[i].cname;
            candidateFile.close();
        }
        cout << "Created Files successfully" << endl;
    }

    void deleteIllegalVote(string userID)
    {
        // Extract the location (index) from the userID in the voterVotes array
        int location = extractNID_No(userID);

        // Determine the index of the candidate whose vote needs to be deleted
        int candidateIndex = voterVotes[location - 1] - '1';

        //2023dhaka00099

        // Decrement the vote count for the corresponding candidate
        candidateArray[candidateIndex].votes--;

        // Mark the vote as deleted in the voterVotes array
        voterVotes[location - 1] = '0';

        // Create the filename for the candidate's data file
        string filename = "candidate" + to_string(candidateIndex + 1) + ".txt";

        // Open the candidate's data file for reading
        ifstream inFile(filename);

        // Create a temporary file for writing
        ofstream tmpFile("tmp.txt");

        // Read the number of votes from the original file and write decremented count to the temporary file
        int numFromFile;
        string cnameFromFile;
        inFile >> numFromFile;
        tmpFile << numFromFile - 1 << endl;

        // Read the candidate's name from the original file and write it to the temporary file
        inFile >> cnameFromFile;
        tmpFile << cnameFromFile << endl;

        // Iterate through the original file and copy non-deleted votes to the temporary file
        while (inFile >> numFromFile)
        {
            if (numFromFile != location)
            {
                tmpFile << numFromFile << endl;
            }
        }

        // Close the input and output files
        inFile.close();
        tmpFile.close();

        // Remove the original candidate's data file
        remove(filename.c_str());

        // Rename the temporary file to the original filename
        rename("tmp.txt", filename.c_str());

        // Print a message indicating successful deletion of the vote
        cout << "\nVote deleted successfully\nPress any key to continue...";
        cin.get();
    }

    int getWinner()
    {
        // Initialize variables to keep track of the maximum votes and the index of the winning candidate
        int maxVotes = -1;
        int winnerIndex = -1;

        // Iterate through the candidateArray to find the candidate with the maximum votes
        for (int i = 0; i < numberOfCandidates; i++)
        {
            // If the current candidate has more votes than the current maximum
            if (candidateArray[i].votes > maxVotes)
            {
                // Update the maximum votes and the index of the winning candidate
                maxVotes = candidateArray[i].votes;
                winnerIndex = i;
            }
            // If there is a tie (current candidate has the same number of votes as the current maximum)
            else if (candidateArray[i].votes == maxVotes)
            {
                // Set the winnerIndex to -1 to indicate a tie
                winnerIndex = -1;
            }
        }

        // Return the index of the winning candidate or -1 if there is a tie
        return winnerIndex;
    }

    void initiateNewElection()
    {
        cout << "\nNew Election Initiation:" << endl;
        cout << "\nElections for which Year: ";
        cin >> currentValidID.year;
        cout << "Enter branch code:";
        cin >> currentValidID.branch;
        cout << "Enter max ID no.:";
        cin >> currentValidID.totalVoters;
        cout << "Enter the no. of candidates:";
        cin >> numberOfCandidates;

        for (int i = 0; i < currentValidID.totalVoters; i++)
        {
            voterVotes[i] = '0';
        }

        for (int i = 0; i < numberOfCandidates; i++)
        {
            candidateArray[i].cid = i + 1;
            cout << "Enter name of candidate " << i + 1 << ": ";
            cin >> candidateArray[i].cname;
            candidateArray[i].votes = 0;
        }
    }

    void adminPanel()
    {
        while (true)
        {
            if (!authenticateAdmin())
            {
                cout << "\n Wrong Username or Password \n";
                break;
            }
            cout << "\n\nLOGGED IN SUCCESSFULLY (Press Enter)";
            cin.ignore();
            cin.get();

            while (true)
            {
                string inputID;
                char input;
                char banInp;
                int winnerIndex, totalVotedNow = 0;
                cout << "\n1.New Election\n2.Continue Previous Election\n3.Delete Illegal Vote\n4.Ban User IDs\n5.Result\n6.Logout\nOption:";
                cin >> input;

                switch (input)
                {
                case '1':
                    initiateNewElection();
                    createCandidateFiles();
                    break;
                case '2':
                    // Load previous election data (if any)
                    cout << "\nLoading Previous Election Data...\n";
                    // Code to load data from files goes here
                    break;
                case '3':
                    cout << "\nEnter user ID to delete its vote: ";
                    cin >> inputID;
                    deleteIllegalVote(inputID);
                    break;
                case '4':
                    cout << "Do you want to ban particular ID's?\nPress 1 if yes or any other key to continue...";
                    cin >> banInp;
                    if (banInp == '1')
                    {
                        banID();
                    }
                    break;
                case '5':
                    winnerIndex = getWinner();
                    if (winnerIndex != -1)
                    {
                        cout << "\nWinner is " << candidateArray[winnerIndex].cname << " with " << candidateArray[winnerIndex].votes << " votes\n";
                    }
                    else
                    {
                        cout << "\nIt's a TIE";
                    }
                    cout << "\nFull Result\n";
                    for (int i = 0; i < numberOfCandidates; i++)
                    {
                        totalVotedNow += candidateArray[i].votes;
                        cout << candidateArray[i].cid << ". " << candidateArray[i].cname << " -> " << candidateArray[i].votes << " votes\n";
                    }
                    cout << "\nVoting Percentage: " << (totalVotedNow * 100) / currentValidID.totalVoters << " %\n\n";
                    break;
                case '6':
                    return;
                default:
                    cout << "Invalid Option";
                    cin.ignore();
                    cin.get();
                }
            }
        }
    }

    bool isValid(string userID)
    {
        if (userID.size() != 14)
        {
            return false;
        }

        int inputedYear = extractYear(userID);
        int inputedRollNo = extractNID_No(userID);

        return inputedYear == currentValidID.year && checkBranchCode(userID);
    }

    bool isVoted(string userID)
    {
        int location = extractNID_No(userID);
        return voterVotes[location - 1] != '0';
    }

    bool isBanned(string userID)
    {
        int location = extractNID_No(userID);
        return voterVotes[location - 1] == '$';
    }

    void saveVote(string userID, char voteInput)
    {
        int location = extractNID_No(userID);
        voterVotes[location - 1] = voteInput;
        candidateArray[voteInput - '1'].votes++;
        string filename = "candidate" + string(1, voteInput) + ".txt";
        ofstream outFile(filename, ios::app);
        outFile << location << endl;
        outFile.close();
    }

    void voterPanel()
    {
        string userID;
        char voteInput;
        while (true)
        {
            cout << "\n\n  To exit press 0";
            cout << "\n  Enter voter ID:";
            cin >> userID;
            if (userID == "0")
            {
                return;
            }
            if (!isValid(userID))
            {
                cout << "\n  Invalid Voter ID(Press Enter)";
                cin.ignore();
                cin.get();
                continue;
            }
            if (isBanned(userID))
            {
                cout << "\nThis Voter ID is currently banned...\nContact Admin for the reason...(Press Enter to continue)";
                cin.ignore();
                cin.get();
                continue;
            }
            if (isVoted(userID))
            {
                cout << "\n  Your PRN entered is already voted\n  Contact Admin for further query";
                cin.ignore();
                cin.get();
                continue;
            }
            cout << "\n\n  Candidates for election:";
            for (int i = 0; i < numberOfCandidates; i++)
            {
                cout << "\n  " << candidateArray[i].cid << ". " << candidateArray[i].cname;
            }
            cout << "\n\n  Your Vote(Enter Number):";
            cin >> voteInput;
            if (voteInput < '1' || voteInput > '9')
            {
                cout << "\nInvalid Vote\nTry Again...";
                cin.ignore();
                cin.get();
                continue;
            }
            saveVote(userID, voteInput);
            cout << "\n\nThanks for your precious vote(Press Enter)";
            cin.ignore();
            cin.get();
        }
    }
};

int main()
{
    ElectionSystem system;
    while (true)
    {
        cout << "\n\t\t\t   1.Voter panel \n\t\t\t   2.Admin panel \n\t\t\t   3.Exit \n\t\t\t   Option:";
        char input;
        cin >> input;

        switch (input)
        {
        case '1':
            system.voterPanel();
            break;
        case '2':
            system.adminPanel();
            break;
        case '3':
            return 0;
        default:
            cout << "\nInvalid option";
            cin.ignore();
            cin.get();
        }
    }
    return 0;
}
