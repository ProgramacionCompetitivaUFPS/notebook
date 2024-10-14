double area(pt &a, pt &b, pt &c) {
    return abs((a.x - c.x)*(b.y - a.y) - (a.x - b.x)*(c.y - a.y));
}

//Compute the diameter of a polygon using rotating-caliper method to generate
//all antipodal pairs. Return the max distance between an antipodal pair extremes.

double diameter(vector<pt> &h) {
    int m = h.size();

    //Return trivial results for polygons with less than 3 points.
    if (m <= 1)
        return 0;
    if (m == 2)
        return abs(h[0] - h[1]);

    //Search the point k which is antipodal of point 0
    int k = 1;
    while (area(h[m - 1], h[0], h[(k + 1) % m]) > area(h[m - 1], h[0], h[k]))
        ++k;

    double res = 0;
    //Generate all antipodal pairs in i,j
    for (int i = 0, j = k; i <= k && j < m; ++i) {
        res = max(res, abs(h[i] - h[j]));
        //Advance point j while j is antipodal pair of i
        while (j < m && area(h[i], h[(i + 1) % m], h[(j + 1) % m]) > area(h[i], h[(i + 1) % m], h[j])) {
            res = max(res, abs(h[i] - h[(j + 1) % m]));
            ++j;
        }
    }
    return res;
}
