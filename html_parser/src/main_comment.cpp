#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main() {
    // This program checks the validity of HTML tags in the given string
    // It uses a stack to make sure that each opening tag has a corresponding closing tag
    // If any tag does not have a matching pair, it reportans an error. Otherwise it confirms the HTML as valid.

    // The HTML string to check for valid tags
    string html_str = "<html><head><title>Website</title></head><body><h1>Big Website</h1><p>big website contest</p></body></html>";
    // Stack to keep track of open HTML tags
    stack<string> st;
    
    // Variables to hold the indices of the opening and closing tags
    int opening_index = 0;
    int closing_index = 0;
    for (int i = 0; i < html_str.length(); i++) {
        if (html_str[i] == '<') {
            opening_index = i;
        } else if (html_str[i] == '>') {
            closing_index = i;
            int slice_len = closing_index - opening_index;
            string slice = "";

            if (html_str[opening_index + 1] == '/') {
                slice = html_str.substr(opening_index + 2, slice_len - 2);
                if (slice != st.top()) {
                    cout << st.top() << " has no closing tag" << endl;
                    return 1;
                }
                st.pop();
                continue;
            }

            slice = html_str.substr(opening_index + 1, slice_len - 1);
            st.push(slice);
        }
    }

    cout << "valid html" << endl;
    return 0;
}
