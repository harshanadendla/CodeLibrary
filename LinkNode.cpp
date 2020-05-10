using namespace std;

class LinkNode
{
    public:
    int val;
    LinkNode *next;

    LinkNode(int val)
    {
        this->val=val;
        next=NULL;
    }
};