(custom-set-variables
  ;; custom-set-variables was added by Custom.
  ;; If you edit it by hand, you could mess it up, so be careful.
  ;; Your init file should contain only one such instance.
  ;; If there is more than one, they won't work right.
 '(grep-find-command "find . -type f -print0 | \"xargs\" -0 -e grep -niH -e ")
 '(inhibit-startup-screen t)
 '(make-backup-files nil)
 '(nxml-child-indent 4)
 '(sql-database "game")
 '(sql-password "lichuan")
 '(sql-user "lichuan"))
(custom-set-faces
  ;; custom-set-faces was added by Custom.
  ;; If you edit it by hand, you could mess it up, so be careful.
  ;; Your init file should contain only one such instance.
  ;; If there is more than one, they won't work right.
 )

;;common
(setq default-buffer-file-coding-system 'gbk)                                                                                                                                    
(prefer-coding-system 'gbk)
(setq default-tab-width 4)
(setq-default indent-tabs-mode nil)
(setq auto-mode-alist(cons '("\\.h$" . c++-mode) auto-mode-alist))

;;color theme
(add-to-list 'load-path
             "/home/lichuan/.emacs.d/color-theme-6.6.0")
(require 'color-theme)
(color-theme-initialize)
(color-theme-arjen)

;;cscope
(add-to-list 'load-path
             "/home/lichuan/.emacs.d/cscope")
(require 'xcscope)

;;multi term
(setq multi-term-program "/bin/bash")
(global-set-key (kbd "C-c m") 'multi-term)
(global-set-key (kbd "C-c n") 'multi-term-next)
(global-set-key (kbd "C-c p") 'multi-term-prev)
(add-to-list 'load-path
             "/home/lichuan/.emacs.d/other")
(require 'multi-term)

;;auto-complete
(add-to-list 'load-path "~/.emacs.d/auto-complete")
(require 'auto-complete-config)
(add-to-list 'ac-dictionary-directories "~/.emacs.d/auto-complete/ac-dict")

(defun my-ac-config ()
  (setq-default ac-sources '(ac-source-abbrev ac-source-dictionary ac-source-words-in-same-mode-buffers))
  (add-hook 'emacs-lisp-mode-hook 'ac-emacs-lisp-mode-setup)
  (add-hook 'c-mode-common-hook 'ac-cc-mode-setup)
  (add-hook 'ruby-mode-hook 'ac-ruby-mode-setup)
  (add-hook 'css-mode-hook 'ac-css-mode-setup)
  (add-hook 'auto-complete-mode-hook 'ac-common-setup)
  (global-auto-complete-mode t))
(my-ac-config)

;;auto-complete-clang
(setq ac-clang-flags
      (mapcar (lambda (item)(concat "-I" item))
              (split-string
               "
 /usr/include/c++/4.7
 /usr/include/c++/4.7/i486-linux-gnu
 /usr/include/c++/4.7/backward
 /usr/lib/gcc/i486-linux-gnu/4.7/include
 /usr/local/include
 /usr/lib/gcc/i486-linux-gnu/4.7/include-fixed
 /usr/include/i386-linux-gnu
 /usr/include
 /home/lichuan/repos/gabriel/src/3rd-party/ACE_wrappers/src
 /home/lichuan/repos/gabriel/src/3rd-party/boost_1_53_0/src
"
               )))
(require 'auto-complete-clang)
(setq ac-auto-start nil)

(defun my-ac-cc-mode-setup ()
  (setq ac-sources (append '(ac-source-clang ac-source-yasnippet) ac-sources)))
(add-hook 'c-mode-common-hook 'my-ac-cc-mode-setup)

;;key bind
(global-set-key (kbd "M-j") 'nil)
(ac-set-trigger-key "M-j")

;;mysql
(global-set-key (kbd "C-c l") 'sql-mysql)

;;lua
(add-to-list 'load-path "/home/lichuan/.emacs.d/lua")
(autoload 'lua-mode "lua-mode" "Lua editing mode." t)
(add-to-list 'auto-mode-alist '("\\.lua$" . lua-mode))
(add-to-list 'interpreter-mode-alist '("lua" . lua-mode))

;;max window
;;windows maximize window
;; (defun w32-restore-frame () 
;;   "Restore a minimized frame" 
;;   (interactive) 
;;   (w32-send-sys-command 61728)) 

;; (defun w32-maximize-frame () 
;;   "Maximize the current frame" 
;;   (interactive) 
;;   (w32-send-sys-command 61488)) 
;; (w32-maximize-frame)

;; ;;unix-like maximize window
;; (defun fullscreen (&optional f)
;;   (interactive)
;;   (x-send-client-message nil 0 nil "_NET_WM_STATE" 32
;;                           '(2 "_NET_WM_STATE_MAXIMIZED_VERT" 0))
;;   (x-send-client-message nil 0 nil "_NET_WM_STATE" 32
;;                           '(2 "_NET_WM_STATE_MAXIMIZED_HORZ" 0)))
;; (add-hook 'window-setup-hook 'fullscreen)


(add-hook 'c-mode-hook
          '(lambda ()
             (c-set-offset 'inline-open 0)))
(add-hook 'c++-mode-hook
          '(lambda ()
             (c-set-offset 'inline-open 0)))

(add-hook 'c-mode-hook
          '(lambda ()
             (c-set-style "stroustrup")))
(add-hook 'c++-mode-hook
          '(lambda ()
             (c-set-style "stroustrup")))

(add-hook 'c-mode-hook
          '(lambda ()
             (c-toggle-auto-newline)))
(add-hook 'c++-mode-hook
          '(lambda ()
             (c-toggle-auto-newline)))
