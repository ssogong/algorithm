function find(m, x) {
  if (!m.has(x))
      return x;
  let r = find(m, m.get(x));
  m.set(x, r);
  return r;
}

function solution(k, room_number) {
  let answer = [];
  let m = new Map();
  for (let room of room_number) {
      let tmp = find(m, room);
      answer.push(tmp);
      m.set(tmp, find(m, tmp+1));
  }
  return answer;
}
