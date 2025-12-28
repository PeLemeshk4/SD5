#include "../Header files/IOBinaryTree.h"
#include <vector>

using namespace std;

vector<BinaryTreeNode*> GetNextNodes(vector<BinaryTreeNode*> nodes)
{
    vector<BinaryTreeNode*> nextNodes;
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

vector<string> GetNextValues(vector<BinaryTreeNode*> nodes)
{
    vector<string> values;
    for (int i = 0; i < nodes.size(); i++)
    {
        if (nodes[i])
        {
            if (nodes[i]->GetLeft())
            {
                values.push_back(to_string(nodes[i]->GetLeft()->GetData()));
            }
            else
            {
                values.push_back("");
            }
            if (nodes[i]->GetRight())
            {
                values.push_back(to_string(nodes[i]->GetRight()->GetData()));
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

string WriteBinaryTree(BinaryTree* tree)
{
    BinaryTreeNode* root = tree->GetRoot();
    if (!root)
    {
        return "Tree is empty.\n";
    }

    vector<vector<string>> values;
    values.push_back({ to_string(root->GetData()) });
    vector<BinaryTreeNode*> nodes = { root };
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
        int indent = pow(2, values.size() - i);
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
            for (int time = 0; time < indent; time++)
            {
                result += " ";
            }
        }
        result += '\n';
    }
    return result;
}

void IOBinaryTree::RunMenu()
{
	string BinaryTreeMenu[] = {
        "=== Binary Search Tree Menu ===",
        "Insert element",
        "Remove element",
        "Search element",
        "Find minimum",
        "Find maximum",
        "Display tree",
        "Clear tree",
        "Exit"
	};
    int size = sizeof(BinaryTreeMenu) / sizeof(BinaryTreeMenu[0]);

    BinaryTree* tree = new BinaryTree();
    while (true)
    {
        int choice = InputWithMessage(WriteManual(BinaryTreeMenu, size));

        switch (choice)
        {
            case 1:
            {
                int data = InputWithMessage("Enter the value for new node: ");
                tree->AddElement(data);

                cout << "Adding is complete.\n";

                break;
            }
            case 2:
            {
                int data = InputWithMessage("Enter the value for removing: ");
                tree->RemoveElement(data);

                cout << "Removing is complete.\n";

                break;
            }
            case 3:
            {
                int data = InputWithMessage("Enter the value for searcing: ");
                BinaryTreeNode* searchedNode = tree->SearchElement(data);
                if (searchedNode)
                {
                    cout << "Pointer of element: " << searchedNode << '\n';
                }
                else
                {
                    cout << "Not found.\n";
                }

                break;
            }
            case 4:
            {
                if (tree->GetRoot())
                {
                    cout << "Min value: " << tree->GetMinNode()->GetData() << '\n';
                }
                else
                {
                    cout << "Tree is empty.\n";
                }

                break;
            }
            case 5:
            {
                if (tree->GetRoot())
                {
                    cout << "Max value: " << tree->GetMaxNode()->GetData() << '\n';
                }
                else
                {
                    cout << "Tree is empty.\n";
                }

                break;
            }
            case 6:
            {
                cout << WriteBinaryTree(tree);

                break;
            }
            case 7:
            {
                tree->Clear();
                cout << "Tree was cleared.\n";

                break;
            }
            case 8:
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