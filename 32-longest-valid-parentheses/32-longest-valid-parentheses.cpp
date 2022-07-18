class Solution {
public:
    int longestValidParentheses(string s) {
       int left = 0, right = 0, maxLength = 0;

  // Left pass iteration
  
  for (int i = 0; i < s.length(); i++)
  {
    // Update left
    if ( s[i] == '(' )
    {
      left++;
    }
  
    // Update right
    else {
      right++;
    }

    // Update the maximum length of valid parentheses
    if (left == right) {
      maxLength = max(maxLength, 2 * right);
    }

    // Updating left and right to '0'
    else if (right >= left) {
      left = 0;
      right = 0;
    }
  }
  left = right = 0;

  // Right pass iteration
  for (int i = s.length() - 1; i >= 0; i--) {
    // Update left
    if (s[i] == '(') {
      left++;
    }

    // Update right
    else {
      right++;
    }

    // Update the maximum length of valid parentheses
    if (left == right) {
      maxLength = max(maxLength, 2 * left);
    }

    // Updating left and right to '0'
    else if (left >= right) {
      left = 0;
      right = 0;
    }
  }
  return maxLength;
    }
};