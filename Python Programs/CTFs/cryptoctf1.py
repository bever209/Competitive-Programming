s="QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm"
#string='sxlq{kyeuxr_js_llp_nask_woep_afmhyidae}'
string="wdjzkhy trsz paxwjvkkw zg aqc wgcow rtqngdo wm dsx!. sfb afty yh sxlq{kyeuxr_js_llp_nask_woep_afmhyidae}. wlqm lwthth elfnl ax itpm cqamhtd bdgf"

for j in range(100):
    output=""
    change=13
    for i in string:
        if change==0:
            change=j
        if i in s:
            output=output+chr(ord(i)-change)
        else:
            output=output+i
        change=change-1
    print (output)
