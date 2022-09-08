#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        // 递归实现
        string s;
        serializeImp(root, s);
        return s;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        return deserializeImp(data);
    }

private:
    void serializeImp(TreeNode* root, string& s)
    {
        // 有空指针，就插入null
        if(nullptr == root)
        {
            s.append("$,");
            return;
        }

        s.append(to_string(root->val));
        s.append(",");

        serializeImp(root->left, s);
        serializeImp(root->right, s);
    }

    bool getNumer(string& data, int& nCurVal)
    {
        string sCurVal;
        int nIndex = 0;
        while(nIndex < data.length())
        {
            if(data[nIndex] == '$')
            {
                ++nIndex;
                break;
            }
            else if(data[nIndex] == ',')
            {
                if(sCurVal.length() > 0)
                {
                    break;
                }
            }
            else
            {
                sCurVal.push_back(data[nIndex]);
            }
            ++nIndex;
        }

        data = data.substr(nIndex);
        if(0 == sCurVal.length())
            return false;

        nCurVal = atoi(sCurVal.c_str());
        return true;
    }

    TreeNode* deserializeImp(string& data)
    {
        int nCurVal = 0;
        if(getNumer(data, nCurVal))
        {
            TreeNode* pCurNode = new TreeNode(nCurVal);
            pCurNode->left = deserializeImp(data);
            pCurNode->right = deserializeImp(data);
            return pCurNode;
        }
        return nullptr;
    }
};

int main(int argc, char** argv)
{
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(3);
    t1->right->left = new TreeNode(4);
    t1->right->right = new TreeNode(5);

    Codec codec;
    string sss = codec.serialize(t1);
    cout << "sss : " << sss << endl;
    TreeNode* t2 = codec.deserialize(sss);

    cout << "\n\n------\n\n";
    cout << t2->val << endl;
    cout << t2->left->val << endl;
    cout << t2->right->val << endl;
    cout << t2->right->left->val << endl;
    cout << t2->right->right->val << endl;
    return 0;
}
