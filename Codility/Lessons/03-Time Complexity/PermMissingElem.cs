
// Session
// ID: training54MQEW-G3C
// Time limit: 120 min.

// Status: closed
// Created on: 2015-10-11 13:07 UTC
// Started on: 2015-10-11 13:07 UTC
// Finished on: 2015-10-11 13:28 UTC

// from https://app.codility.com/demo/results/training54MQEW-G3C/

// see also you blog post on this: http://jboyflaga2.blogspot.com/2015/10/frustration-during-college-solving.html


using System;
// you can also use other imports, for example:
// using System.Collections.Generic;

// you can write to stdout for debugging purposes, e.g.
// Console.WriteLine("this is a debug message");

class Solution {
    public int solution(int[] A) {
        // write your code in C# 6.0 with .NET 4.5 (Mono)
        
        int N = A.Length;        
        if (N <= 0) { return 1;}
        
        int[] A_copy = new int[A.Length + 2];
        //for (int i = 0; i< A_copy.Length;i++) { A_copy[i] = -1; }
        
        for(int i = 0; i < A.Length; i++)
        {
            int elem = A[i];
            A_copy[elem] = elem;
        }
        
        // you can replace this with O(log(n)) next time
        for(int i = 1; i < A_copy.Length; i++)
        {
            if (A_copy[i] != i) 
            { 
                return i; 
            }
        }
        
        return 1;
    }
}