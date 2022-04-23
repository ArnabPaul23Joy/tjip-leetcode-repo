class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        char topStChar = '*';
        for (int i = 0; i < s.length(); i++)
        {
            switch (s[i])
            {
            case '(':
                st.push(s[i]);
                break;
            case '{':
                st.push(s[i]);
                break;
            case '[':
                st.push(s[i]);
                break;
            case ')':
                if (st.empty())
                {
                    return false;
                }
                topStChar = st.top();
                if (topStChar == '(')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
                break;
            case '}':
                if (st.empty())
                {
                    return false;
                }
                topStChar = st.top();
                if (topStChar == '{')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
                break;
            case ']':
                if (st.empty())
                {
                    return false;
                }
                topStChar = st.top();
                if (topStChar == '[')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
                break;
            }
        }
        if (st.empty())
        {
            return true;
        }
        return false;
    }
};