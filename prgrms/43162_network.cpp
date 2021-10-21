/*
---
title:  "[C++] PRGRMS_43162_네트워크"
excerpt: "https://www.acmicpc.net/problem/43162"
toc: true
toc_sticky: true
toc_label: "Contents"
categories:
  - algorithm
tags:
  - BOJ
  - BFS
---

문제이해: 4분
구현: 19분
Debug: 5분
참고자료
*/

#include "stdio.h"
#include <string>
#include <vector>
#include <queue>

using namespace std;

void bfs(int start, int *visited, vector<vector<int>> graph, int n){
    int v;
    visited[start] = 1;
    queue<int> q;
    q.push(start);
    
    // graph[node1][node2] = 1 -> node1과 node2 연결
    
    while(!q.empty()){
        v = q.front();
        q.pop();
        for(int i = 0; i < n; ++i){
            // printf("$d", i);
            if(!visited[i] && graph[v][i] == 1){
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int visited[n];
    
    // 배열 초기화
    for(int i = 0; i < n; ++i){
        visited[i] = 0;
    }
    
    for(int i = 0; i < n; ++i){
        if(!visited[i]){
            bfs(i, visited, computers, n);
            answer += 1;
        }
    }
    return answer;
}