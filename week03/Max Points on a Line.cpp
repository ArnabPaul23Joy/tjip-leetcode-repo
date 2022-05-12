class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int maxPntNum = 1;
        for (int i = 0; i < points.size(); i++)
        {
            int tempPoints = 1;
            for (int j = i + 1; j < points.size(); j++)
            {
                tempPoints = 2;
                double tangnt = 300000000;
                if (points[j][0] - points[i][0] != 0)
                    tangnt = (points[j][1] - points[i][1]) / (1.0 * points[j][0] - points[i][0]);
                for (int k = j + 1; k < points.size(); k++)
                {
                    if (points[j][0] - points[i][0] == 0)
                    {
                        if (points[k][0] - points[j][0] == 0)
                        {
                            tempPoints++;
                        }
                    }
                    else
                    {
                        if (points[k][0] - points[j][0] != 0)
                        {
                            double thrdPointTngt = (points[k][1] - points[j][1]) / (1.0 * points[k][0] - points[j][0]);
                            if (thrdPointTngt == tangnt)
                            {
                                tempPoints++;
                            }
                        }
                    }
                }
                maxPntNum = max(maxPntNum, tempPoints);
            }
            maxPntNum = max(maxPntNum, tempPoints);
        }
        return maxPntNum;
    }
};