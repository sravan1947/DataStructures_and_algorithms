class Solution {
public:
   vector< string> f_ans;
    unordered_set<string> ust;
    struct Node 
    {
        Node *trie[26]={NULL};
        bool flag=0;
    }*root=NULL;
    
    Node* newnode()
    {
        Node *temp = new Node ;
        
        return(temp);
    }
    void addWord(string &word) {
        if(root==NULL)
        {
            root=newnode();
        }
        Node* temp=root;
        int n=word.length();
        for(int i=0;i<n;i++)
        {
            if(temp->trie[word[i]-'a']==NULL)
            {
                temp->trie[word[i]-'a']=newnode();
            }
            temp=temp->trie[word[i]-'a'];
        }
        temp->flag=true;
    }
    
    void dfs(Node *root,vector<vector<char>>& board,int i,int j,int &n,int &m,string st)
    {

         if(root->flag)
            ust.insert(st);
        if(i<0||j<0||i>=n||j>=m||board[i][j]=='#')
            return;
         char c=board[i][j];
         
        if(root->trie[c-'a']==NULL)
            return;
        board[i][j]='#';
        dfs(root->trie[c-'a'],board,i+1,j,n,m,st+c);
        dfs(root->trie[c-'a'],board,i,j+1,n,m,st+c);
        dfs(root->trie[c-'a'],board,i-1,j,n,m,st+c);
        dfs(root->trie[c-'a'],board,i,j-1,n,m,st+c);
         board[i][j]=c;
                
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        for(auto i: words)
            addWord(i);
        
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(root->trie[board[i][j]-'a'])
                {
                    string st="";
                    dfs(root,board,i,j,n,m,st);
                }
            }
        }
        for(auto i:ust)
        {
            f_ans.push_back(i);
        }
        return(f_ans);
    }
};