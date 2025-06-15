## 📌 #36 [week7] choitaejin

[그리디 알고리즘] [5585] 문제 풀이
[수학, 그리디 알고리즘] [1789] 문제풀이
[그리디 알고리즘, 정렬] [1946] 문제풀이

---

## ✅ 해결한 문제
- [ ] 문제 1 거스름 돈 (https://www.acmicpc.net/problem/5585)
- [ ] 문제 2 수들의 합 (https://www.acmicpc.net/problem/1789)
- [ ] 문제 3 신입 사원 (https://www.acmicpc.net/problem/1946)
- [ ] 문제 4 제목 (문제 링크)

---

## 💡 문제 해결 방법 및 핵심 로직
### - 문제 1: (5585) 거스름 돈
  - 해결 방법: 
    - 큰 숫자부터 계산해서 거스름돈을 주면 가장 적은 동전을 줄 수 있게된다.
  - 핵심 로직: 
    - `Math.floor(res / 동전)` 으로 해당 동전 개수 구하고, `res %= 동전`으로 나머지 갱신
    - `Math.floor()`를 써야 1.5 이렇게 소수점이 안나온다.

```javascript
let input, res;
let change = 0;

rl.on('line', (line) => {
  
  input = parseInt(line);
  // 거스름돈 계산
  res = 1000 - input;
  
  // 500엔부터 차례대로 나눠주기
  change += Math.floor(res / 500);
  res %= 500;

  change += Math.floor(res / 100);
  res %= 100;

  change += Math.floor(res / 50);
  res %= 50;

  change += Math.floor(res / 10);
  res %= 10;

  change += Math.floor(res / 5);
  res %= 5;

  change += Math.floor(res / 1);
  rl.close();

})
```

### - 문제 2: (1789) 수들의 합
  - 해결 방법:
    - 1부터 input까지 더하면서 count 해주면 된다.
  - 핵심 로직:
    - 계속 더하다가 input보다 커진 경우 처리를 해줘야함

```javascript
let input;
let cnt = 0;

rl.on('line', (line) => {
  
  input = parseInt(line);
  let i = 1;
  let sum = 0;
  
  // 1부터 차례대로 더하면서 input을 넘지 않는 최대 개수 찾기
  while (sum <= input) {
    sum += i;
    cnt++;
    i++;
  }

  // 합이 input을 넘어갔으므로 개수 하나 빼기
  if (sum > input) cnt--;

  rl.close();

})
```

### - 문제 3: (1946) 신입 사원
  - 해결 방법:
    - 서류 성적과 면접 성적 둘 다 다른 지원자보다 떨어지면 탈락
  - 핵심 로직:
    - 서류 성적 오름차순 정렬 후, 면접 성적의 최솟값을 갱신하면서 카운트
    - `if (newbi[i][1] < minInterview)` 현재 면접 순위가 최소값보다 좋으면 선발

```javascript
let t;
let lineCnt = 0;
let newbi = [];
let test = 0;
let n = 0;
let internCnt = 0;
let res = [];

rl.on('line', (line) => {
    if (lineCnt == 0) {
        t = parseInt(line);
        lineCnt++;
    }
    else {
        if (internCnt == 0) {
            n = parseInt(line);
            newbi = [];
            internCnt++;
        }
        else {
            let [first, second] = line.split(' ').map(Number);
            newbi.push([first, second]);
            internCnt++;
            
            if (internCnt > n) {
                // 서류 성적 기준 오름차순 정렬
                newbi.sort((a, b) => a[0] - b[0]);
                
                let cnt = 1; // 서류 1등은 무조건 선발
                let minInterview = newbi[0][1]; // 현재까지 최고 면접 순위
                
                // 서류 순위대로 확인하면서 면접 순위 체크
                for (let i = 1; i < n; i++) {
                    if (newbi[i][1] < minInterview) {
                        cnt++;
                        minInterview = newbi[i][1];
                    }
                }
                
                res.push(cnt);
                test++;
                internCnt = 0;
                
                if (test == t) {
                    rl.close();
                }
            }
        }
    }
})
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
  - 미루다가 대충 풀어서 좀 코드가 너무 긴 거 같은데 나중에 로직을 조금 변경하면 line이 줄어들 것 같다.

- 추가로 개선할 사항 : X
