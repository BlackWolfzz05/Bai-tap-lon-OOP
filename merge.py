import os
import re

files_order = [
    r'bac_si\bacsi.h',
    r'co_so_vat_chat\phongbenh.h',
    r'hoa_don\hoadon.h',
    r'he_thong\danhmuc.h',
    r'benh_nhan\benhnhan.h',
    r'benh_vien\benhvien.h',
    r'bac_si\bacsi.cpp',
    r'co_so_vat_chat\phongbenh.cpp',
    r'he_thong\danhmuc.cpp',
    r'hoa_don\hoadon.cpp',
    r'benh_nhan\benhnhan.cpp',
    r'benh_vien\benhvien.cpp',
    r'main.cpp'
]

std_includes = set()
content_blocks = []

for filepath in files_order:
    try:
        with open(filepath, 'r', encoding='utf-8') as f:
            lines = f.readlines()
            
            filtered_lines = []
            for line in lines:
                stripped = line.strip()
                if stripped.startswith('#include <'):
                    std_includes.add(stripped)
                    continue
                if stripped.startswith('#include "') or stripped.startswith('#include \"'):
                    continue
                
                # Very simple heuristic for standard header guards
                if stripped.startswith('#ifndef') and '_H' in stripped:
                    continue
                if stripped.startswith('#define') and '_H' in stripped:
                    continue
                if stripped == '#endif' or stripped.startswith('#endif //'):
                    # only skip if it's likely a header guard ending
                    if filepath.endswith('.h'): 
                        # We will skip all #endif in .h assuming no other directives are used
                        continue
                        
                if stripped.startswith('using namespace std;'):
                    continue
                    
                filtered_lines.append(line)
            content_blocks.append("".join(filtered_lines))
    except Exception as e:
        print(f"Error processing {filepath}: {e}")

with open('sanpham2.cpp', 'w', encoding='utf-8') as cout:
    for inc in sorted(list(std_includes)):
        cout.write(inc + '\n')
    cout.write('using namespace std;\n\n')
    
    for block in content_blocks:
        cout.write(block)
        cout.write('\n')
        
print("Successfully merged into sanpham2.cpp")
