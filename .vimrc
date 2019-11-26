" All system-wide defaults are set in $VIMRUNTIME/debian.vim and sourced by
" the call to :runtime you can find below.  If you wish to change any of those
" settings, you should do it in this file (/etc/vim/vimrc), since debian.vim
" will be overwritten everytime an upgrade of the vim packages is performed.
" It is recommended to make changes after sourcing debian.vim since it alters
" the value of the 'compatible' option.

" This line should not be removed as it ensures that various options are
" properly set to work with the Vim-related packages available in Debian.
runtime! debian.vim

" Vim will load $VIMRUNTIME/defaults.vim if the user does not have a vimrc.
" This happens after /etc/vim/vimrc(.local) are loaded, so it will override
" any settings in these files.
" If you don't want that to happen, uncomment the below line to prevent
" defaults.vim from being loaded.
" let g:skip_defaults_vim = 1

" Uncomment the next line to make Vim more Vi-compatible
" NOTE: debian.vim sets 'nocompatible'.  Setting 'compatible' changes numerous
" options, so any other options should be set AFTER setting 'compatible'.
"set compatible

" Vim5 and later versions support syntax highlighting. Uncommenting the next
" line enables syntax highlighting by default.
if has("syntax")
  syntax on
endif

" If using a dark background within the editing area and syntax highlighting
" turn on this option as well
"set background=dark

" Uncomment the following to have Vim jump to the last position when
" reopening a file
"if has("autocmd")
"  au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
"endif

" Uncomment the following to have Vim load indentation rules and plugins
" according to the detected filetype.
"if has("autocmd")
"  filetype plugin indent on
"endif

" The following are commented out as they cause vim to behave a lot
" differently from regular Vi. They are highly recommended though.
"set showcmd		" Show (partial) command in status line.
"set showmatch		" Show matching brackets.
"set ignorecase		" Do case insensitive matching
"set smartcase		" Do smart case matching
"set incsearch		" Incremental search
"set autowrite		" Automatically save before commands like :next and :make
"set hidden		" Hide buffers when they are abandoned
"set mouse=a		" Enable mouse usage (all modes)

" Source a global configuration file if available
if filereadable("/etc/vim/vimrc.local")
  source /etc/vim/vimrc.local
endif
inoremap ( ()<ESC>i
inoremap [ []<ESC>i
inoremap { {}<ESC>i
"inoremap < <><ESC>i
inoremap " ""<ESC>i
inoremap <C-l> <ESC>la
inoremap <C-k> <ESC>ka
inoremap <C-h> <ESC>ha
inoremap <C-j> <ESC>ja

inoremap <A-Down> <ESC>:m+1<ENTER>a
inoremap <A-Up> <ESC>:m-2<ENTER>a

nnoremap <A-Down> <ESC>:m+1<ENTER>a
nnoremap <A-Up> <ESC>:m-2<ENTER>a

"设置多行注释
vnoremap <C-m> I//<ESC><ESC>

"ctrl+d删除一行
inoremap <C-d> <ESC>dda

"复制到剪贴板
inoremap <C-a> <ESC>ggVG
nnoremap <C-a> <ESC>ggVG
vnoremap <C-c> "+y

nnoremap <C-Left> :vertical res -1<ENTER>
nnoremap <C-Right> :vertical res +1<ENTER>
nnoremap <C-Up> :res -1<ENTER>
nnoremap <C-Down> :res +1<ENTER>

set sw=4
set ts=4
set number
""set cursorline
set ruler
set smartindent
set ignorecase
set incsearch

" 设置std头文件路径
" set path=/usr/include/c++/7/
" 设置path=/usr/include/
set path+=.,./usr/include,../include,/usr/include/**,/usr/local/include
set tags+=./tags,/usr/include/tags

inoremap { {<CR>}<ESC>kA<CR>

" set spell "设置拼写错误高亮



" ycm 自动补全插件 start

call plug#begin('~/.vim/plugged')

" 要安装的插件写在两个call之间
"	Plug 'Valloric/YouCompleteMe'

" 开始界面的小奶牛
Plug 'mhinz/vim-startify'

"默认配置文件路径"
let g:ycm_global_ycm_extra_conf = '~/.ycm_extra_conf.py'
"打开vim时不再询问是否加载ycm_extra_conf.py配置"
let g:ycm_confirm_extra_conf=0
set completeopt=longest,menu
"python解释器路径"
let g:ycm_path_to_python_interpreter='/usr/bin/python'
"是否开启语义补全"
let g:ycm_seed_identifiers_with_syntax=1
"是否在注释中也开启补全"
let g:ycm_complete_in_comments=1
let g:ycm_collect_identifiers_from_comments_and_strings = 0
"开始补全的字符数"
let g:ycm_min_num_of_chars_for_completion=1
"补全后自动关机预览窗口"
let g:ycm_autoclose_preview_window_after_completion=1
" 禁止缓存匹配项,每次都重新生成匹配项"
let g:ycm_cache_omnifunc=0
"字符串中也开启补全"
let g:ycm_complete_in_strings = 1
"离开插入模式后自动关闭预览窗口"
"autocmd InsertLeave * if pumvisible() == 0|pclose|endif
"上下左右键行为"
inoremap <expr> <Down>     pumvisible() ? '\<C-n>' : '\<Down>'
inoremap <expr> <Up>       pumvisible() ? '\<C-p>' : '\<Up>'
inoremap <expr> <PageDown> pumvisible() ? '\<PageDown>\<C-p>\<C-n>' : '\<PageDown>'
inoremap <expr> <PageUp>   pumvisible() ? '\<PageUp>\<C-p>\<C-n>' : '\<PageUp>'


call plug#end()
" ycm 自动补全插件 end
