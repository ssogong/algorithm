let map = {};
function comb(strLi, idx, score) {
  let tmp = [...strLi];
  tmp[idx] = '-';
  for (let i = idx+1; i < 4; i++) {
    comb(tmp, i, score);
  }
  tmp = tmp.join('');
  if (map[tmp] == undefined)
    map[tmp] = [score];
  else
    map[tmp].push(score);
}

function find(li, low, high, target) {
  if (li[high] < target)
    return 0;
  else if (li[low] >= target)
    return high+1;
  while(low != high && li[low] < target) {
    let mid = Math.floor((high-low) / 2);
    if (li[mid] <= target)
      low = mid;
    else
      high = mid;
  }
  return high-low+1;
}

function solution(info, query) {
  var answer = [];
  // map 만들기
  map['----'] = [];
  for (let i of info) {
    let tmp = i.split(' ');
    let score = tmp[4];
    tmp = tmp.slice(0, -1);
    comb(tmp, 0, score);
    tmp = tmp.join('');
    if (map[tmp] == undefined)
      map[tmp] = [score];
    else
      map[tmp].push(score);
  }
  console.log(map);
  // 정렬
  for (let key in map) {
    map[key].sort((a, b) => a - b);
  }
  // query
  for (let q of query) {
    let q = q.split(' and ');
    let tmp = q[3].split(' ');
    q[3] = tmp[0];
    let score = tmp[1];
    q = q.join('');
    if (map[q] == undefined)
      answer.push(0);
    else {
      let tmp = map[q];
      find(tmp, 0, tmp.length-1, )
    }

  }
  return answer;
}
// console.log(find([1,2,3,4,4,5], 0, 5, 2))

console.log(solution(["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"],
["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]))