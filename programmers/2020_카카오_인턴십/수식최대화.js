function comb(tmp, visited,list, map) {
    if (tmp.length == list.length) {
        map.push([...tmp]);
        return;
    }
    for (let j = 0; j < list.length; j++) {
        if (!visited[j]) {
            visited[j] = 1;
            tmp.push(list[j]);
            comb(tmp, visited, list, map);
            tmp.pop();
            visited[j] = 0;
        }
    }
}
function cal(nums, exs, ex) {
    let eIdx = exs.indexOf(ex);
    let a = nums[eIdx];
    let b = nums[eIdx+1];
    let re = 0;
    if (ex == '+')
        re = a + b;
    else if (ex == '-')
        re = a -b;
    else
        re = a * b;
    exs.splice(eIdx, 1);
    nums.splice(eIdx, 2, re);
}

function solution(expression) {
    var answer = 0;
    let nums = expression.match(/\d+/g).map(Number);
    let exs = expression.match(/[\+\-\*]/g);
    let exSet = [...new Set(exs)];
    let visited = [];
    for (let i = 0; i < exSet.length; i++)
        visited.push(0);
    let co = [];
    comb([], visited,  exSet, co);
    for (let eS of co) {
        let tmpNums = [...nums];
        let tmpExs = [...exs];
        for (let e of eS) {
            while(tmpExs.indexOf(e) != -1) {
                cal(tmpNums, tmpExs, e);
            }
        }
        if (Math.abs(tmpNums[0]) > answer)
            answer = Math.abs(tmpNums[0]);
    }
    return answer;
}

console.log(solution("100-200*300-500+20"))