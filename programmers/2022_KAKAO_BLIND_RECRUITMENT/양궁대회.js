function solution(n, info) {
  let answer = [-1];
  let tmp_ans = new Array(11).fill(0);
  let tmp_score = -Infinity;
  const ifLionWin = () => {
      let peach = lion = 0;
      for (let i = 0, tmp = 10; i < info.length; i++, tmp--) {
          if (info[i] >= tmp_ans[i])
              peach += tmp;
          else if (tmp_ans[i] > 0)
              lion += tmp;
      }
      if (lion > peach)
          return lion - peach;
      return -1;
  }
  const DFS = (now, idx) => {
      if (now === 0) {
          let s = ifLionWin();
          if (s != -1 && s >= tmp_score) {
              answer = [...tmp_ans];
              tmp_score = s;
          }
          return;
      }
      for (let i = idx; i < info.length; i++) {
          if (now <= info[i] && i != 10)
              continue;
          if (now <= info[i] && i === 10) {
              tmp_ans[i] += now;
              DFS(0, i+1);
              tmp_ans[i] -= now;
          } else {
              tmp_ans[i] += (info[i] + 1);
              DFS(now - (info[i]+1), i+1);
              tmp_ans[i] -= (info[i] + 1);
          }
      }
  }
  DFS(n, 0);
  return answer;
}

console.log(solution(5, [2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0]))
//console.log(solution(9, [0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1]));
//console.log(solution(10, [0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3]))