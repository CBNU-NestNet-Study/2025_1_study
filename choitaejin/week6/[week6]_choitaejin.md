## 📌 #35 [week6] choitaejin

[누적합] [11659] 문제 풀이
[누적합, 두 포인터, 슬라이딩 윈도우] [2559] 문제풀이
[DP, 누적 합] [11660] 문제풀이


---

## ✅ 해결한 문제
- [ ] 문제 1 구간 합 구하기 4 (https://www.acmicpc.net/problem/11659)
- [ ] 문제 2 수열 (https://www.acmicpc.net/problem/2559)
- [ ] 문제 3 구간 합 구하기 5 (https://www.acmicpc.net/problem/11660)
- [ ] 문제 4 제목 (문제 링크)

---

## 💡 문제 해결 방법 및 핵심 로직
### - 문제 1: 11659
  - 해결 방법: 무지성 for문으로 푸니까 시간초과 나와서 누적합 개념 써야했음.
    - 누적합이란? 미리 n번째까지의 합을 구해둔 배열을 만드는 것
    - 처음 제출한 for문으로 그때 그때 합을 구하면 O(n*m)이지만 누적합 방식은 O(n+m)이다.

  - 핵심 로직: 
    - 누적합 점화식 `prefixSum[i] = prefixSum[i-1] + array[i];` 를 코드로 구현하면 된다.

```javascript
let lineCnt = 0;
let n, m;
let arr = [];
let prefixSum = [];

rl.on('line', (line) => {
    let num;
    if (lineCnt == 0) {
        // N, M 입력받기
        num = line.split(' ').map(Number);
        n = num[0];
        m = num[1];
        lineCnt++;
    }
    else if (lineCnt == 1) {
        // 배열 입력 받기
        arr = line.split(' ').map(Number);

        // 누적합 배열 초기화
        prefixSum[0] = 0;
        for (let i = 1; i <= n; i++) {
            // 누적합 배열 i는 이전 누적합 배열의 합에 새로운 숫자 하나 더하면 됨
            /* ex) prefixSum[3] = prefixSum[2] + arr[2]
                   prefixSum[2] = prefixSum[1] + arr[1]
                   prefixSum[1] = prefixSum[0] + arr[0]
                   prefixSum[0] = 0으로 초기화
            */
            prefixSum[i] = prefixSum[i-1] + arr[i-1];
        }
        lineCnt++;
    }
    // M개의 입력 받기
    else if (lineCnt >= 2 && lineCnt < m+2) {
        let ij = line.split(' ').map(Number);
        let i = ij[0];
        let j = ij[1]; 
        
        // i번째부터 j번째까지의 합이니 누적합에서 j - i된 값을 return 해주면 됨
        console.log(prefixSum[j] - prefixSum[i-1])
        lineCnt++;
    }
```

### - 문제 2: 2559
  - 해결 방법: 
    - 슬라이딩 윈도우를 사용해서 문제를 풀면 된다.
    - 연속되는 날짜의 온도 합이므로 중복된 부분과 변경되는 부분을 체크해서 수식을 작성하였다.

  - 핵심 로직:
    - 연속된 K개의 배열의 합들을 구할 때 windowSum은 기존 합에서 `다음 windowSum = 새로운 끝 값(index: i) - 시작 값(index: i-k)` 이 수식을 코드로 구현하면된다.

```javascript
let lineCnt = 0;
let n, k;
let arr = [];

rl.on('line', (line) => {
    if (lineCnt == 0) {
      // N, K 입력받기
      const nk = line.split(' ').map(Number);
      n = nk[0];
      k = nk[1];
      lineCnt++;
    }
    else if (lineCnt == 1) {
      // 온도 배열 입력받기
      arr = line.split(' ').map(Number);

      // 먼저 0부터 K까지의 합으로 온도의 합 최대 초기화
      let windowSum = 0;
      for (let i = 0; i < k; i++) {
          windowSum += arr[i];
      }
      let maxSum = windowSum;

      // index K이후부터 배열 끝까지 연속된 K일의 온도 합을 비교하면서 최대값 구하기
      for (let i = k; i < n; i++) {
          windowSum = windowSum - arr[i-k] + arr[i];
          maxSum = Math.max(windowSum, maxSum);
      }
      console.log(maxSum);

      rl.close();
    }

})
```

### - 문제 3: 11660
  - 해결 방법:
    - 누적합을 DP로 쓰면 될 거 같음
    - 2차원 배열 누적합 구하기, 계산할 때 중복되는 부분 체크하기
  
  - 핵심 로직:
    - **2차원 배열 누적 합 배열 점화식**
    ```javascript
    /* i = 1 to n
       j = 1 to n */
    prefix[i][j] = prefix[i-1][j] // 위쪽 더하고
                 + prefix[i][j-1] // 왼쪽 더하고
                 - prefix[i-1][j-1] // 중복 빼고
                 + arr[i-1][j-1]; // 현재 칸 값 더하기
    ```
    - **result 점화식**
    ```javascript
    // x1,x2,y1,y2 는 입력받은 좌표 값
    const result = prefix[x2][y2]           // 전체
                 - prefix[x1-1][y2]         // 위쪽 빼고
                 - prefix[x2][y1-1]         // 왼쪽 빼고고
                 + prefix[x1-1][y1-1];      // 겹친 부분 다시 더하고 (중요)
    ```

```javascript
let n, m;
let lineCnt = 0;
let arr = [];
let arrIdx = 0;
let cmd = [];
let cmdIdx = 0;
let prefix = [];

rl.on('line', (line) => {
  if (lineCnt == 0) {
      
      // N, M 입력받기
      const temp = line.split(' ').map(Number);
      n = temp[0];
      m = temp[1];
      
      // 필요한 배열들 초기화
      arr = Array(n).fill().map(() => Array(n).fill(0));
      cmd = Array(m).fill().map(() => Array(4).fill(0));
      prefix = Array(n+1).fill().map(() => Array(n+1).fill(0));
      
      lineCnt++;
    }
  else if (lineCnt > 0 && lineCnt < n+1) {
    
    // N*N 배열 입력 받기 
    arr[arrIdx] = line.split(' ').map(Number);
    arrIdx++;
    lineCnt++;
  }
  else if (lineCnt > n && lineCnt <= n + m) {
    
    // 합을 구해야하는 횟수 M 입력받기
    cmd[cmdIdx] = line.split(' ').map(Number);
    cmdIdx++;
    lineCnt++;
  }
  else rl.close();
});
rl.on('close', () => {
  // N*N 배열의 누적합 배열 생성
  for (let i = 1; i <=n; i++) {
      for (let j = 1; j <= n; j++) {
          prefix[i][j] = prefix[i-1][j] // 위쪽 더하고
                       + prefix[i][j-1] // 왼쪽 더하고
                       - prefix[i-1][j-1] // 중복 빼고
                       + arr[i-1][j-1]; // 현재 칸 값 더하기
      }
  }

  for (let k = 0; k < m; k++) {
      // cmd 배열을 좌표로 할당
      let x1 = cmd[k][0];
      let y1 = cmd[k][1];
      let x2 = cmd[k][2];
      let y2 = cmd[k][3];

      // 포함-배제 원리 적용해서 결과 구하기
      const result = prefix[x2][y2]           // 전체
                    - prefix[x1-1][y2]         // 위쪽 빼고
                    - prefix[x2][y1-1]         // 왼쪽 빼고
                    + prefix[x1-1][y1-1];      // 겹친 부분 다시 더하고 (중요)

     console.log(result);
  }

  process.exit();
});
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

- 고민했던 부분이나 어려웠던 점 : 
  - 누적합, 슬라이딩 윈도우 개념은 쉬워서 배우고 풀어보니 금방 풀었다.
  - 마지막 문제에 거의 다 풀었는데 작은 오차가 계속 나왔는데 중복 부분을 다시 안 더해줘서 문제가 생겼던 것 이었다.

- 추가로 개선할 사항 :
  - (https://chanhuiseok.github.io/posts/baek-19/) 11660번 개념 이해할 때 도움된 블로그