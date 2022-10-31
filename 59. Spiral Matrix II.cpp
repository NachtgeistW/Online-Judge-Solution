class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int offset = 1;
        int len = n - offset, //右边界长度
            start_x = 0, start_y = 0, loop_time = n / 2, mid = n / 2, num = 1;
        while (loop_time-- > 0)
        {
            //up
            for (int i = start_x; i < len; i++)
            {
                matrix[start_x][i] = num;
                num++;
            }
            //right
            for (int i = start_y; i < len; i++)
            {
                matrix[i][len] = num;
                num++;
            }
            //bottom
            for (int i = len; i > start_x; i--)
            {
                matrix[len][i] = num;
                num++;
            }
            //up
            for (int i = len; i > start_y; i--)
            {
                matrix[i][start_x] = num;
                num++;
            }
            len -= offset;
            start_x++;
            start_y++;
        }
        
        //Process odd number
        if (n % 2 != 0)
        {
            matrix[mid][mid] = num;
        }
            
        return matrix;

    }
};
