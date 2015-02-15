" MUST BE FIRST THING
" Set 'nocompatible' to ward off unexpected things that your distro might
" have made, as well as sanely reset options when re-sourcing .vimrc
set nocompatible

" enable syntax highlighting
syntax enable

" Allows buffers to be hidden
set hidden

"stores hostname for font settings
"let hostname = substitute(system('hostname'), '\n', '', '')

if has("gui_running")
"initial size
set lines=40 columns=90
colorscheme molokai 
set background=dark
set guifont=DejaVu_Sans_Mono:h10,Consolas:h10,Fixedsys

"else
    "console settings block
    "if exists("+lines")
    "    set lines=50
    "endif
    "if exists("+columns")
    "    set columns=100
    "endif
    "256 color mode
    "set t_Co=256 

    "colorscheme desert  
endif 


"file based theme changing
"autocmd BufEnter * colorscheme molokai 
"autocmd BufEnter *.cpp colorscheme molokai
"autocmd BufEnter *.py colorscheme molokai

"disable word wrap
set nowrap

"show line numbers
set number

" Show partial commands in the last line of the screen
set showcmd

" Attempt to determine the type of a file based on its name and possibly its
" contents. Use this to allow intelligent auto-indenting for each filetype,
" and for plugins that are filetype specific.
filetype indent plugin on

" Modelines have historically been a source of security vulnerabilities. As
" such, it may be a good idea to disable them and use the securemodelines
" script, <http://www.vim.org/scripts/script.php?script_id=1876>.
set nomodeline

" Instead of failing a command because of unsaved changes, instead raise a
" dialogue asking if you wish to save changed files.
set confirm

"disable default splash text
set shortmess+=Iat

" Sets how many lines of history VIM has to remember
set history=7000

" Set to auto read when a file is changed from the outside
set autoread

"Show matching brackets when text indicator is over them
set showmatch 

" Ignore case when searching
set ignorecase

" Set command line height to avoid Hit Enter to to continue prompts
set cmdheight=2

" No annoying sound on errors
set noerrorbells
set novisualbell
set t_vb=
set tm=500

" Set utf8 as standard encoding and en_US as the standard language
set encoding=utf8

" Turn backup off, since most stuff is in SVN, git et.c anyway...
set nobackup
set nowb
set noswapfile

" Use spaces instead of tabs
set expandtab

" 1 tab == 4 spaces
set tabstop=4
set shiftwidth=4
set softtabstop=4

"use multiple shiftwidths when indenting with <, >
set shiftround


" Always show the status line
set laststatus=2


" statusline
" cf the default statusline: %<%f\ %h%m%r%=%-14.(%l,%c%V%)\ %P
" format markers:
"   %< truncation point
"   %n buffer number
"   %f relative path to file
"   %m modified flag [+] (modified), [-] (unmodifiable) or nothing
"   %r readonly flag [RO]
"   %y filetype [ruby]
"   %= split point for left and right justification
"   %-35. width specification
"   %l current line number
"   %L number of lines in buffer
"   %c current column number
"   %V current virtual column number (-n), if different from %c
"   %P percentage through buffer
"   %) end of width specification
set statusline+=%F%m%r%h\ %w\ CWD:%r%{getcwd()}%h\ %y[Line:%l][Col:%c]


" Configure backspace so it acts as it should act
set backspace=eol,start,indent
set whichwrap+=<,>,h,l

" Don't redraw while executing macros (good performance config)
set lazyredraw

" Highlight search results
set hlsearch

"show search matches as you type
set incsearch

"insert tabs at the start of a line according to shiftwidth not tabstop
set smarttab

" 80 col lines
set textwidth=80

"set autoindenting on
set autoindent

set colorcolumn=80

augroup myvimrc
    au!
    au BufWritePost .vimrc,_vimrc,vimrc,.gvimrc,_gvimrc,gvimrc so $MYVIMRC | if has('gui_running') | so $MYGVIMRC | endif
augroup END

set guioptions-=r  "remove right-hand scroll bar
set guioptions-=L  "remove left-hand scroll bar

"au VimEnter * vsplit
