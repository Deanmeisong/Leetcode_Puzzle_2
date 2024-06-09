class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        sb = []
        for i in range(len(s)-1, -1, -1):
            if s[i] != '-':
                if len(sb) % (k+1) == k:
                    sb.append('-')
                sb.append(s[i])
        return ''.join(sb[::-1]).upper()