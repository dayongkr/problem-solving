function _gcd(a: number, b: number) {
  if(b === 0) return a;
  else return _gcd(b, a % b);
}


function gcdOfStrings(str1: string, str2: string): string {
    const str1_length = str1.length, str2_length = str2.length
    const gcd = _gcd(str1_length, str2_length)
    const prefix = str1.substring(0, gcd);

    for(let i = 0; i < str1_length; i += gcd) {
        if(str1.substring(i, i + gcd) !== prefix) return ""
    }

    for(let i = 0; i < str2_length; i += gcd) {
        if(str2.substring(i, i + gcd) !== prefix) return ""
    }

    return prefix
};