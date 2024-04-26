#include <stdlib.h>
//הקוד יעבור עבור השורה הראשונה ואז יבדוק כמה  תת מטריצות  בשורה סכומן נותנות את המספר המבוקש
//אם יש עוד שורה אז נאחד את השורה  הראשונה והשנייה לשורה שתסכום את שניהן ואז נבדוק בה כמה תת מטריצות מקיימות
//אם אין עוד שורות אז נבדוק רק את השנייה לבד ובסוף נסכום את כל כמות התת מטריצות שענו לנו על השאלה

int numSubmatrixSumTarget(int** matrix, int matrixSize, int* matrixColSize, int target)//This function send to check the first row and then first and second combine like 1 row. and if there is another row in will incldude 1+2+3 row like one row to check. and then will send 2 row and after 2 +3 row and after it will send 3 row. and in the end it will return the num of all the submetrics that their sum is equal to target. 
{
    int res = 0;
    int m = matrixSize, n = matrixColSize[0];// here we get the num of rows and coulmns

    for (int i = 0; i < m; i++)//here start with first row until last row
    {
        int rowSum[n];
        memset(rowSum, 0, sizeof(rowSum));//start the row for checking with all 0 and than will copy the rows.
        for (int j = i; j < m; j++)//here we will add to which row all the rows below him so for row 1 we will send for 
            //checking row 1 and than row 1 + 2 and than 1 + 2 + 3 (if we have 3 rows). and then for row 2 it will send row 2 
            //than row 2 + 3 and finally only row 3. 
        {
            for (int k = 0; k < n; k++) // here we will add the value of the rows.
                rowSum[k] += matrix[j][k];
            res += subarraySum(rowSum, n, target);
        }
    }

    return res; // return how many submetrics match the request.
}

int subarraySum(int* nums, int numsSize, int k)//This function return the number of submetrics that their sum equal to target
{
    int count = 0, sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum = 0;
        for (int j = i; j < numsSize; j++) {
            sum += nums[j];
            if (sum == k)
                count++;
        }
    }
    return count;
}
