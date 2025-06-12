const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

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
rl.on('close', () => {
  process.exit();
});