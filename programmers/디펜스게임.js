function solution(N, K, enemy) {
    let answer = 0;
    const ifCanDefence = (right) => {
        if (K >= right)
            return true;
        let tmpArr = enemy.slice(0, right).sort((a,b) => a - b);
        let sum = 0;
     	console.log(tmpArr)
        for (let i = 0; i < tmpArr.length - K; i++)
            sum += tmpArr[i];
        if (N >= sum)
            return true;
        else
            return false;
    };
    let l = 0;
    let r = enemy.length;
    let mid = Math.floor((l + r) / 2);
    while (l <= r) {
        if (ifCanDefence(mid)) {
            l = mid + 1;
        }
        else
            r = mid - 1;
        mid = Math.floor((l + r) / 2);
    }
    return l - 1;
}

