function solution(user_id, banned_id) {
  let answer = 0;
  let matched = [];
  for (let b_id of banned_id) {
      let tmp = [];
      let re = new RegExp('^'+b_id.replace(/\*/g, '\.')+'$', 'g');
      for (let user of user_id) {
          if (user.match(re) != null) {
              tmp.push(user);
          }
      }
      matched.push(tmp);
  }
  let map = new Map();
  let q = [{'n': 0, 'data': []}];
  while (q.length > 0) {
      let nowNode = q.shift();
      let n = nowNode.n;
      let data = nowNode.data;
      if (n == matched.length) {
          map.set(data.sort().join(''), new Map(data));
          continue;
      }
      for (let user of matched[n]) {
          let tmp_data = [...data, user];
          q.push({'n': n+1, 'data': tmp_data});
      }
  }
  for (let data of map.values()) {
      if (data.size == matched.length)
          answer++;
  }
  return answer;
}
console.log(solution(["frodo", "fradi", "crodo", "abc123", "frodoc"],["*rodo", "*rodo", "******"]))