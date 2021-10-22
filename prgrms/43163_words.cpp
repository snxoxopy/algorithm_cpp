/*
---
title:  "[C++] PRGRMS_43163_단어변환"
excerpt: "https://www.acmicpc.net/problem/43163"
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

#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// queue를 사용하기 위한 구조체 사용
typedef struct{
    string str;
    int cnt;
} lst;

bool check(string word, string begin){
    int ans = 0;
    // 한 개만 일치하는지 확인
    for(int i = 0; i < word.size(); ++i){
        if(word[i] != begin[i]) ans += 1;
    }
    if(ans == 1) return true;
    else return false;
}


int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    // config.
    map<string, int> visited;
    queue<lst> q;
    visited[begin] = 1;
    q.push({begin, 0});
    
    // BFS
    while(!q.empty()){
        lst cur = q.front();
        q.pop();
        
        // target을 찾으면 cnt를 반환
        if(target == cur.str) return cur.cnt;
        
        for(int i = 0; i < words.size(); ++i){
            if(visited[words[i]] == 0 && check(words[i], cur.str)){
                visited[words[i]] = 1;
                q.push({words[i], cur.cnt + 1});
            }
        }
    }
    return answer;
}