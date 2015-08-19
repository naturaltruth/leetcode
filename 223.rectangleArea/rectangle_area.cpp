/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: rectangle_area.cpp,v 0.0 2015-08-19 星期三 22:27:28  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   rectangle_area.cpp
 * @author zhoujin
 * @date   2015-08-19 星期三 22:27:28
 * @mail   zhoujin1224@gmail.com
 * @brief  Find the total area covered by two rectilinear rectangles in a 2D plane.
 *
 * Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
 *
 * Rectangle Area
 * Assume that the total area is never beyond the maximum possible value of int.
 *
 **/

#include <iostream>

using namespace std;

class Solution {
  public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = 0;
        area += _abs((C - A) * (D - B)) + _abs((G - E) * (H - F));

        int max_ac = A > C ? A : C;
        int min_ac = A < C ? A : C;
        int max_bd = B > D ? B : D;
        int min_bd = B < D ? B : D;
        int max_eg = E > G ? E : G;
        int min_eg = E < G ? E : G;
        int max_fh = F > H ? F : H;
        int min_fh = F < H ? F : H;

        if (!(max_ac <= min_eg || min_ac >= max_eg || max_bd <= min_fh || min_bd >= max_fh)) {
            // 相交
            int mid_aceg1 = max_ac > max_eg ? max_eg : max_ac;
            int mid_aceg2 = min_ac > min_eg ? min_ac : min_eg;
            int mid_bdfh1 = max_bd > max_fh ? max_fh : max_bd;
            int mid_bdfh2 = min_bd > min_fh ? min_bd : min_fh;
            area -= _abs((mid_aceg1 - mid_aceg2) * (mid_bdfh1 - mid_bdfh2));
        }

        return area;
    }

  private:
    int _abs(int a) {
        return a > 0 ? a : -a;
    }
};


int main() {
    Solution sol = Solution();
    cout << sol.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
    cout << sol.computeArea(-2, -2, 2, 2, -2, -4, 2, -2) << endl;
    cout << sol.computeArea(-2, -2, 2, 2, 1, -3, 3, -1) << endl;

    return 0;
}
