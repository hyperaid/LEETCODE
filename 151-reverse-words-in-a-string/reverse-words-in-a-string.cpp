class Solution
{
    public:
        string reverseWords(string s)
        {
            stack<string> st;
            int n = s.length();
            string temp = "";
            for (int i = 0; i < n; i++)
            {
                if (s[i] != ' ')
                {
                    temp += s[i];
                }
                else if (temp != "")
                {
                    st.push(temp);
                    temp = "";
                }
            }
            if (temp != "")
            {
                st.push(temp);
            }

            // st.push(temp);

            cout << st.size();
            string usman = "";

            while (!st.empty())
            {
                usman += st.top();
                st.pop();
                if (!st.empty())
                {
                    usman += " ";
                }
            }
            return usman;
        }
};