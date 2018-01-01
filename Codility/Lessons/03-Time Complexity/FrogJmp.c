	
// Session
// ID: trainingTRB9A9-Z7Z
// Time limit: 120 min.

// Status: closed
// Created on: 2015-10-08 08:46 UTC
// Started on: 2015-10-08 08:46 UTC
// Finished on: 2015-10-08 08:50 UTC

// from https://app.codility.com/demo/results/trainingTRB9A9-Z7Z/

// see also you blog post on this: http://jboyflaga2.blogspot.com/2015/10/frustration-during-college-solving.html

int solution(int X, int Y, int D) {
    // write your code in C99
    int distanceBetweenXandY = Y - X;
    
    if (X > Y) { return 0; }
    else if (distanceBetweenXandY % D == 0) { return (distanceBetweenXandY / D); }
    else { return (distanceBetweenXandY /D) + 1; }
}