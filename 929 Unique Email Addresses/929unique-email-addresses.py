class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        result_set = set()
        for i in emails:
            local , domain = i.split("@")
            if "+" in local:
                local = local[:local.index("+")]
            if "." in local:
                local = local.replace("." , "")

            newstr = local + "@" + domain
            result_set.add(newstr)
        
        return len(result_set)
            
