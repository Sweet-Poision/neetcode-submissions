class Solution:

    def check(self, row: List[str]) -> bool:
        checker = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '.']
        list_a = []
        for a in row:
            if a not in checker:
                return False
            if a in list_a:
                return False
            if a != '.':
                list_a.append(a)
            

    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(len(board)):
            check_list_h = []
            check_list_v = []
            for j in range(len(board[0])):
                check_list_h.append(board[i][j])
                check_list_v.append(board[j][i])
            if self.check(check_list_h) == False:
                return False
            if self.check(check_list_v) == False:
                return False

        for row in range(0, 9, 3):       
            for col in range(0, 9, 3):    
                subgrid = []
                for i in range(row, row + 3):
                    for j in range(col, col + 3):
                        subgrid.append(board[i][j])
                
                if self.check(subgrid) == False:
                    return False
        
        return True
            