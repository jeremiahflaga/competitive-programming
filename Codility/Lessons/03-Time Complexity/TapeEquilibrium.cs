
// Session
// ID: trainingX95N7D-W2Z
// Time limit: 120 min.

// Status: closed
// Created on: 2015-10-06 09:57 UTC
// Started on: 2015-10-06 09:57 UTC
// Finished on: 2015-10-06 10:03 UTC

// from https://app.codility.com/demo/results/trainingX95N7D-W2Z/

// see also you blog post on this: http://jboyflaga2.blogspot.com/2015/10/frustration-during-college-solving.html

using System;
// you can also use other imports, for example:
// using System.Collections.Generic;

// you can write to stdout for debugging purposes, e.g.
// Console.WriteLine("this is a debug message");

class Solution {
    public int solution(int[] A) {
        // write your code in C# 6.0 with .NET 4.5 (Mono)
        int[] arr_first, arr_second;
        int min_difference = Int32.MaxValue;
        int sum_first = 0;
        int sum_second = 0;
        for (int i = 0; i < A.Length; i++)
        {
            sum_second += A[i];
        }
        
        for (int P = 0; P < A.Length - 1; P++)
        {
            sum_first += A[P];
            sum_second -= A[P];
            int difference = Math.Abs(sum_first - sum_second);
            if (difference < min_difference)
            {
                min_difference = difference;   
            }            
        }
        
        return min_difference;
    }
}