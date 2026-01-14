#include "../Header files/IOTreap.h"
#include <vector>
#include <iostream>

using namespace std;

vector<TreapNode*> GetNextNodes(vector<TreapNode*> nodes)
{
    vector<TreapNode*> nextNodes;
    for (int i = 0; i < nodes.size(); i++)
    {
        if (nodes[i])
        {
            nextNodes.push_back(nodes[i]->GetLeft());
            nextNodes.push_back(nodes[i]->GetRight());
        }
        else
        {
            nextNodes.push_back(nullptr);
            nextNodes.push_back(nullptr);
        }
    }
    return nextNodes;
}

vector<string> GetNextValues(vector<TreapNode*> nodes)
{
    vector<string> values;
    for (int i = 0; i < nodes.size(); i++)
    {
        if (nodes[i])
        {
            if (nodes[i]->GetLeft())
            {
                values.push_back(to_string(nodes[i]->GetLeft()->GetKey()) +
                    "[" + to_string(nodes[i]->GetLeft()->GetPriority()) + "]");
            }
            else
            {
                values.push_back("");
            }
            if (nodes[i]->GetRight())
            {
                values.push_back(to_string(nodes[i]->GetRight()->GetKey()) +
                    "[" + to_string(nodes[i]->GetRight()->GetPriority()) + "]");
            }
            else
            {
                values.push_back("");
            }
        }
        else
        {
            values.push_back("");
            values.push_back("");
        }
    }
    return values;
}

string WriteTreap(Treap* treap)
{
    int length = 2;

    TreapNode* root = treap->GetRoot();
    if (!root)
    {
        return "Treap is empty.\n";
    }

    vector<vector<string>> values;
    values.push_back({ to_string(root->GetKey()) +
        "[" + to_string(root->GetPriority()) + "]" });
    vector<TreapNode*> nodes = { root };
    bool f = true;
    while (f)
    {
        f = false;
        vector<string> nextValues = GetNextValues(nodes);
        values.push_back(nextValues);
        nodes = GetNextNodes(nodes);
        for (int i = 0; i < nodes.size(); i++)
        {
            if (nodes[i])
            {
                f = true;
            }
        }
    }

    string result = "";
    for (int i = 0; i < values.size(); i++)
    {
        int size = values[values.size() - 1].size();
        int indent = pow(2, values.size() - i + 1);
        for (int j = 0; j < values[i].size(); j++)
        {        
            if (j == 0)
            {
                for (int time = 1; time < indent / 2; time++)
                {
                    result += " ";
                }
            }
            result += values[i][j];
            for (int time = 0; time < indent - values[i][j].length(); time++)
            {
                result += " ";
            }
        }
        result += '\n';
    }
    return result;
}

void IOTreap::RunMenu()
{
    string TreapMenu[] = {
        "=== Treap Menu ===",
        "Insert (Unoptimized - 1 Split, 2 Merge)",
        "Insert (Optimized - 1 Split)",
        "Remove (Unoptimized - 2 Split, 1 Merge)",
        "Remove (Optimized - 1 Merge)",
        "Search element",
        "Split tree",
        "Merge trees",
        "Display tree",
        "Clear tree",
        "Exit"
    };
    int size = sizeof(TreapMenu) / sizeof(TreapMenu[0]);

    Treap* treap = new Treap();
    while (true)
    {
        int choice = InputWithMessage(WriteManual(TreapMenu, size));

        switch (choice)
        {
            case 1:
            {
                int key = InputWithMessage("Enter the key for new node: ");
                int priority = InputWithMessage("Enter the priority for new node: ");
                treap->InsertUnoptimized(key, priority);

                cout << "Insert is complete.\n";

                break;
            }
            case 2:
            {
                int key = InputWithMessage("Enter the key for new node: ");
                int priority = InputWithMessage("Enter the priority for new node: ");
                treap->SetRoot(treap->InsertOptimized(treap->GetRoot(), key, priority));

                cout << "Insert is complete.\n";

                break;
            }
            case 3:
            {
                int key = InputWithMessage("Enter the key for removing: ");
                treap->RemoveUnoptimized(key);

                cout << "Removing is complete.\n";

                break;
            }
            case 4:
            {
                int key = InputWithMessage("Enter the key for removing: ");
                treap->SetRoot(treap->RemoveOptimized(treap->GetRoot(), key));

                cout << "Removing is complete.\n";

                break;
            }
            case 5:
            {
                int key = InputWithMessage("Enter the key for searcing: ");
                int priority = treap->FindElement(key);
                if (priority != -1)
                {
                    cout << "Priority of element: " << priority << '\n';
                }
                else
                {
                    cout << "Not found.\n";
                }

                break;
            }
            case 6:
            {


                break;
            }
            case 7:
            {


                break;
            }           
            case 8:
            {
                cout << WriteTreap(treap);

                break;
            }
            case 9:
            {
                treap->Clear(treap->GetRoot());
                cout << "Treap was cleared.\n";

                break;
            }
            case 10:
            {
                exit(0);
            }
            default:
            {
                cout << "Incorrect choice.\n";
                break;
            }
        }
    }
}