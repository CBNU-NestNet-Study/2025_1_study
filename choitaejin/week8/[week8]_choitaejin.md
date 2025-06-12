## 📌 #47 [week8] choitaejin

[그래프 이론, 그래프 탐색, 정렬, 깊이 우선 탐색] [24479] 알고리즘 수업 - 깊이 우선 탐색 1 문제 풀이
[그래프 이론, 그래프 탐색, 정렬, 너비 우선 탐색] [24444] 알고리즘 수업 - 너비 우선 탐색 1 문제풀이

---

## ✅ 해결한 문제
- [ ] 문제 1 알고리즘 수업 - 깊이 우선 탐색 1 (https://www.acmicpc.net/problem/24479)
- [ ] 문제 2 알고리즘 수업 - 너비 우선 탐색 1 (https://www.acmicpc.net/problem/24444)
- [ ] 문제 3 제목 (문제 링크)
- [ ] 문제 4 제목 (문제 링크)

---

## 💡 문제 해결 방법 및 핵심 로직
### - 문제 1: (24479) 알고리즘 수업 - 깊이 우선 탐색 1
  - 해결 방법: 
    - pesudo code를 바탕으로 DFS 구현하는 문제
  - 핵심 로직: 
    - 재귀 호출로 깊이 우선 탐색을 구현하고, cnt++로 방문 순서 관리하기

```javascript
let lineCnt = 0;
let n, m, r;
let graph = [];
let visited = []; // 0이면 미방문, 숫자면 방문순서
let cnt = 1;

// dfs 함수
const dfs = (node) => {
  if (!visited[node]) { // 현재 노드가 아직 방문되지 않았다면
    visited[node] = cnt++; // 방문 처리 및 순서 기록 (cnt를 할당 후 1 증가)
    
    // 현재 노드의 모든 인접 노드들을 재귀적으로 탐색
    for (const next of graph[node]) {
      dfs(next); // 재귀 호출로 깊이 우선 탐색 진행
    }
  }
};

rl.on('line', (line) => {
  if (lineCnt === 0) {
    // 첫 번째 줄: 정점 수 n, 간선 수 m, 시작 정점 r 입력
    [n, m, r] = line.split(" ").map(Number);
    
    // 그래프 초기화: 1번부터 n번까지 사용하므로 n+1 크기로 생성
    // 각 인덱스마다 빈 배열을 생성하여 인접 리스트 구조 만들기
    graph = Array.from({length: n + 1}, () => []);
    // 방문 배열 초기화: 0은 미방문, 양수는 방문 순서
    visited = new Array(n + 1).fill(0); // 0 (미방문)으로 초기화
    
    lineCnt++;
  } else if (lineCnt <= m) {
    // 간선 정보 입력: u와 v 사이에 양방향 간선 존재
    const [u, v] = line.split(" ").map(Number);
    
    // 무방향 그래프이므로 양쪽 방향으로 간선 추가
    graph[u].push(v); // u에서 v로 가는 간선
    graph[v].push(u); // v에서 u로 가는 간선
    
    lineCnt++;
    
    // 모든 간선 정보를 입력받았으면 dfs 실행
    if (lineCnt > m) {
      // 각 정점의 인접 리스트를 오름차순으로 정렬
      // 문제에서 요구하는 "인접 정점을 오름차순으로 방문" 조건 충족
      graph.map(v => v.sort((a, b) => a - b));
      
      // dfs 탐색 시작 - 시작 정점 r부터 깊이 우선 탐색 진행
      dfs(r);
      
      // 결과 출력: 1번 정점부터 n번 정점까지의 방문 순서
      // 방문하지 않은 정점은 0이 출력됨
      for (let i = 1; i <= n; i++) {
        console.log(visited[i]);
      }
      
      rl.close();
    }
  }
});
```

### - 문제 2: (24444) 알고리즘 수업 - 너비 우선 탐색 1
  - 해결 방법:
    - pesudo code를 바탕으로 BFS 구현하는 문제
  - 핵심 로직:
    - DFS와 달리 큐를 이용해서 너비 우선으로 탐색
    - `queue.push()`로 정점 추가, `queue.shift()`로 정점 제거

```javascript
let lineCnt = 0;
let n, m, r;
let graph = [];
let visited = []; // 0이면 미방문, 숫자면 방문순서
let cnt = 1;

// BFS 함수
const bfs = (start) => {
  const queue = [start]; // 큐에 시작 정점 추가
  visited[start] = cnt++; // 시작 정점 방문 처리
  
  while (queue.length > 0) {
    const current = queue.shift(); // 큐에서 정점 꺼내기
    
    // 현재 정점의 모든 인접 정점들을 확인
    for (const next of graph[current]) {
      if (!visited[next]) { // 아직 방문하지 않은 정점이면
        visited[next] = cnt++; // 방문 처리 및 순서 기록
        queue.push(next); // 큐에 추가하여 나중에 탐색
      }
    }
  }
};

rl.on('line', (line) => {
  if (lineCnt === 0) {
    // 첫 번째 줄: 정점 수 n, 간선 수 m, 시작 정점 r 입력
    [n, m, r] = line.split(" ").map(Number);
    
    // 그래프 초기화: 1번부터 n번까지 사용하므로 n+1 크기로 생성
    graph = Array.from({length: n + 1}, () => []);
    // 방문 배열 초기화: 0은 미방문, 양수는 방문 순서
    visited = new Array(n + 1).fill(0); // 0 (미방문)으로 초기화
    
    lineCnt++;
  } else if (lineCnt <= m) {
    // 간선 정보 입력: u와 v 사이에 양방향 간선 존재
    const [u, v] = line.split(" ").map(Number);
    
    // 무방향 그래프이므로 양쪽 방향으로 간선 추가
    graph[u].push(v);
    graph[v].push(u);
    
    lineCnt++;
    
    // 모든 간선 정보를 입력받았으면 bfs 실행
    if (lineCnt > m) {
      // 각 정점의 인접 리스트를 오름차순으로 정렬
      graph.map(v => v.sort((a, b) => a - b));
      
      // bfs 탐색 시작
      bfs(r);
      
      // 결과 출력: 1번 정점부터 n번 정점까지의 방문 순서
      // 방문하지 않은 정점은 0이 출력됨
      for (let i = 1; i <= n; i++) {
        console.log(visited[i]);
      }
      
      rl.close();
    }
  }
});
```

### - 문제 3:
  - 해결 방법:
  - 핵심 로직:
```
  코드를 입력해주세요
```

### - 문제 4:
  - 해결 방법:
  - 핵심 로직:
```
  코드를 입력해주세요
```

---

## ✨ 기타 참고 사항
- 예제 입력/출력과 실행 결과 : 

- 고민했던 부분이나 어려웠던 점 : X

- 추가로 개선할 사항 : X