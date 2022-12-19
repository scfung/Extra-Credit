//Stanley Fung
//Program finds the longest common subsequence between two words in O(mn) time and outputs the longest common subsequence and the length of the longest common subsequence.
#include <iostream>
#include <string>

using namespace std;

int subsequence_driver(int argc, char **argv) {
    //Please place all functionality in here instead of the main.
    //Feel free to make any functions or objects you wish, as long as we only call this function.
    std::string word_1 = argv[1];
    std::string word_2 = argv[2];
    int word_size1= word_1.size(),word_size2 = word_2.size(); //Gets the size of both words to use in function
    int matrix[word_size1+1][word_size2+1];
    string longest_common_sub;
    //For finding the length of the longest common subsequence
    int dp[word_size1+1][word_size2+1];
    for(int i=0;i<=word_size1;i++)dp[i][0]=0;
    for(int i=0;i<=word_size2;i++)dp[0][i]=0;
    for(int i=1;i<=word_size1;i++){
        for(int j=1;j<=word_size2;j++){
            if(word_1[i-1]==word_2[j-1])dp[i][j]=1+dp[i-1][j-1];
            else {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        //For printing out the longest common subsequence
        int word_size1_temp = word_size1,word_size2_temp = word_size2;
        while(word_size1_temp>0 && word_size2_temp>0){    //Make sure string size is not empty
            //If the character matches in both words match, add the character to the longest common subsequence string
            if(word_1[word_size1_temp-1]==word_2[word_size2_temp-1]){
                longest_common_sub+=word_1[word_size1_temp-1];
                word_size1_temp--;word_size2_temp--;
            }
            else{
                //Else, moves the index up or left depending on the current position of the index in the matrix.
                if(dp[word_size1_temp][word_size2_temp-1]>dp[word_size1_temp-1][word_size2_temp])word_size2_temp--;
                else word_size1_temp--;
                }
        }
    //String is reversd, since the resultant string was added backwards.
    reverse (longest_common_sub.begin(),longest_common_sub.end());
    std::cout << dp[word_size1][word_size2] << std::endl << longest_common_sub << std::endl;
    
    return 0;
}

int main(int argc, char **argv)
    {
    if (argc != 3) {
		cout << "Usage: " << argv[0] << "<word_a>" << "<word_b>" << endl;
		return 0;
    }

    subsequence_driver(argc, argv);
    return 0;
}
