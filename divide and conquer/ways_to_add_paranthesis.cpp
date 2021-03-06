/*
 * iteration 1:
			2 - 1- 1 + 1
		   /   \
		  2 - (1-1+1)
		 /	   /  \
		2	- (1 - (1+1))
		
		then
		
			2 - 1- 1 + 1
		   /   \
		  2 - (1-1+1)
		 /	     /  \
		2 - ((1 -1)+1)
		
This give us
1.  2-(1 - (1+1))=3
2.  2 -(1 -1)+1))=1


iteration 2:
		2 - 1 - 1 + 1
		    /   \
		(2 -1)-(1 + 1)
this give us
1. (2-1)-(1+1) = -1

iteration 3:
			2 - 1- 1 + 1
				   /   \
		   (2 - 1 - 1) + 1
			 / \          \
		   (2 - (1 -  1)) +  1
		   
		   then 
		   
		   2 - 1- 1 + 1
				   /   \
		   (2 - 1 - 1) + 1
			     / \      \
		 ((2 - 1) -  1) +  1
this give us
1. 2 - (1 -  1)) +  1=3
2. ((2 - 1) -  1) +  1=1

So the solution is [3,1,-1,3,1]
 * 
 * 
 * */




bool isOperator(char op) 
{ 
    return (op == '+' || op == '-' || op == '*'); 
} 
  
//  Utility recursive method to get all possible 
// result of input string 
vector<int> possibleResultUtil(string input, 
            map< string, vector<int> > memo) 
{ 
    //  If already calculated, then return from memo 
    if (memo.find(input) != memo.end()) 
        return memo[input]; 
  
    vector<int> res; 
    for (int i = 0; i < input.size(); i++) 
    { 
        if (isOperator(input[i])) 
        { 
            // If character is operator then split and 
            // calculate recursively 
            vector<int> resPre = 
              possibleResultUtil(input.substr(0, i), memo); 
            vector<int> resSuf = 
              possibleResultUtil(input.substr(i + 1), memo); 
  
            //  Combine all possible combination 
            for (int j = 0; j < resPre.size(); j++) 
            { 
                for (int k = 0; k < resSuf.size(); k++) 
                { 
                    if (input[i] == '+') 
                        res.push_back(resPre[j] + resSuf[k]); 
                    else if (input[i] == '-') 
                        res.push_back(resPre[j] - resSuf[k]); 
                    else if (input[i] == '*') 
                        res.push_back(resPre[j] * resSuf[k]); 
                } 
            } 
        } 
    } 
  
    // if input contains only number then save that  
    // into res vector 
    if (res.size() == 0) 
        res.push_back(atoi(input.c_str())); 
  
    // Store in memo so that input string is not  
    // processed repeatedly 
    memo[input] = res; 
    return res; 
} 
  
//  method to return all possible output  
// from input expression 
vector<int> possibleResult(string input) 
{ 
    map< string, vector<int> > memo; 
    return possibleResultUtil(input, memo); 
} 
  
//  Driver code to test above methods 
int main() 
{ 
    string input = "5*4-3*2"; 
    vector<int> res = possibleResult(input); 
  
    for (int i = 0; i < res.size(); i++) 
        cout << res[i] << " "; 
    return 0; 
} 



//related question:   https://leetcode.com/problems/expression-add-operators/

























