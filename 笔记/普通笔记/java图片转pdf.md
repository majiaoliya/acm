用这个jar包[jar](/home/majiao/桌面/笔记/普通笔记/img/com.lowagie.text-2.1.7.jar)

```java
package majiao;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

import javax.imageio.ImageIO;

import com.lowagie.text.BadElementException;
import com.lowagie.text.Document;
import com.lowagie.text.DocumentException;
import com.lowagie.text.Image;
import com.lowagie.text.Rectangle;
import com.lowagie.text.pdf.PdfWriter;

/**
 * 将多张图片合并转为PDF；需要用到iTextpdf包，
 * 
 * @author 浴缸
 * 
 */
public class PrintToPdfUtil {
	/**
	 * 
	 * @param imageFolderPath
	 *            图片文件夹地址
	 * @param pdfPath
	 *            PDF文件保存地址
	 * 
	 */
	public static void toPdf(String imageFolderPath, String pdfPath) {
		try {
			// 图片文件夹地址
			// String imageFolderPath = "D:/Demo/ceshi/";
			// 图片地址
			String imagePath = null;
			// PDF文件保存地址
			// String pdfPath = "D:/Demo/ceshi/hebing.pdf";
			// 输入流
			FileOutputStream fos = new FileOutputStream(pdfPath);
			// 创建文档
			Document doc = new Document(null, 0, 0, 0, 0);
			//doc.open();
			// 写入PDF文档
			PdfWriter.getInstance(doc, fos);
			// 读取图片流
			BufferedImage img = null;
			// 实例化图片
			Image image = null;
			// 获取图片文件夹对象
			File file = new File(imageFolderPath);
			File[] files = file.listFiles();
			List<File> fileList = Arrays.asList(files);
			Collections.sort(fileList, new Comparator<File>() { 
				@Override public int compare(File o1, File o2) { 
					if (o1.isDirectory() && o2.isFile()) 
						return -1; 
					if (o1.isFile() && o2.isDirectory()) 
						return 1;
					return o1.getName().compareTo(o2.getName()); 
					} 
				});
			
			// 循环获取图片文件夹内的图片
			for (File file1 : files) {
				if (file1.getName().endsWith(".png")
						|| file1.getName().endsWith(".jpg")
						|| file1.getName().endsWith(".gif")
						|| file1.getName().endsWith(".jpeg")
						|| file1.getName().endsWith(".tif")) {
					// System.out.println(file1.getName());
					imagePath = imageFolderPath + file1.getName();
					System.out.println(file1.getName());
					// 读取图片流
					img = ImageIO.read(new File(imagePath));
					// 根据图片大小设置文档大小
					doc.setPageSize(new Rectangle(img.getWidth(), img
							.getHeight()));
					// 实例化图片
					image = Image.getInstance(imagePath);
					// 添加图片到文档
					doc.open();
					doc.add(image);
				}
			}
			// 关闭文档
			doc.close();
		} catch (IOException e) {
			e.printStackTrace();
		} catch (BadElementException e) {
			e.printStackTrace();
		} catch (DocumentException e) {
			e.printStackTrace();
		}
	}
	public static void main(String[] args) {
		long time1 = System.currentTimeMillis();
		toPdf("/home/majiao/桌面/pixiv/HaMao无修/[Hamao] 白詰草の恋文 (COMIC 快楽天 2016年12月号) [中国翻訳]/", 
				"/home/majiao/桌面/fuck.pdf");
		long time2 = System.currentTimeMillis();
		int time = (int) ((time2 - time1)/1000);
		System.out.println("执行了："+time+"秒！");
	}

}

```

