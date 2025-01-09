package mypackage;

import org.eclipse.core.commands.AbstractHandler;
import org.eclipse.core.commands.ExecutionEvent;
import org.eclipse.core.commands.ExecutionException;
import org.eclipse.swt.widgets.Control;
import org.eclipse.ui.IWorkbenchPart;
import org.eclipse.ui.PlatformUI;
import org.eclipse.ui.texteditor.ITextEditor;

public class ButtonSizeHandler extends AbstractHandler {
    @Override
    public Object execute(ExecutionEvent event) throws ExecutionException {
        IWorkbenchPart part = PlatformUI.getWorkbench().getActiveWorkbenchWindow().getActivePage().getActivePart();
        if (part instanceof ITextEditor) {
            ITextEditor editor = (ITextEditor) part;
            // ابحث عن التحكمات (Controls) الخاصة بالأزرار واستخدمها لتغيير حجم الأزرار
            Control control = (Control) editor.getAdapter(Control.class);
            if (control != null) {
                control.setSize(1000, 1000); // تغيير حجم الزر
            }
        }
        return null;
    }
}
