function solution(n, wires) {
  let answer = Infinity;
  let visited = new Array(n+1).fill(0);
  let map = {};
  for (let i = 1; i <= n; i++)
      map[i] = [];
  for (let w of wires) {
      map[w[0]].push(w[1]);
      map[w[1]].push(w[0]);
  }
  const DFS = (now) => {
      let child_cnt = 1;
      visited[now] = 1;
      for (let to of map[now]) {
          if (visited[to])
              continue;
          let tmp_cnt = DFS(to);
          child_cnt += tmp_cnt;
          answer = Math.min(Math.abs(n - tmp_cnt - tmp_cnt), answer);
      }
      return child_cnt;
  }
  DFS(1)
  return answer;
}